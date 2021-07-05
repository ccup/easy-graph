#include <cctest/cctest.h>
#include "easy_graph/matcher/negative_matcher.h"
#include "easy_graph/matcher/conjunctive_matcher.h"
#include "easy_graph/matcher/disjunctive_matcher.h"

USING_EG_NS

namespace {
	struct AlwaysMatcher : Matcher {
		explicit AlwaysMatcher(bool v) : value(v) {
		}

	private:
		bool eval() const {
			return value;
		}

	private:
		bool value;
	};
}

FIXTURE(MatcherTest) {
	AlwaysMatcher alwaysTrue{true};
	AlwaysMatcher alwaysFalse{false};

	TEST("should match true when using always true") {
        ASSERT_TRUE(matcher_eval(alwaysTrue));
    }

	TEST("should match false when using always false") {
        ASSERT_FALSE(matcher_eval(alwaysFalse));
    }

	TEST("should match false when using negative true") {
		NegativeMatcher negTrue{alwaysTrue};
        ASSERT_FALSE(matcher_eval(negTrue));
    }

	TEST("should match true when using negative false") {
		NegativeMatcher negfalse{alwaysFalse};
        ASSERT_TRUE(matcher_eval(negfalse));
    }

	TEST("should match true when none false in conjunctive matcher") {
		ConjunctiveMatcher conjunction;
		conjunction.add(alwaysTrue);
		conjunction.add(alwaysTrue);
        ASSERT_TRUE(matcher_eval(conjunction));
    }

	TEST("should match false when false in conjunctive matcher") {
		ConjunctiveMatcher conjunction;
		conjunction.add(alwaysTrue);
		conjunction.add(alwaysFalse);
        ASSERT_FALSE(matcher_eval(conjunction));
    }

	TEST("should match true when one true in disjunctive matcher") {
		DisjunctiveMatcher disjunction;
		disjunction.add(alwaysFalse);
		disjunction.add(alwaysTrue);
        ASSERT_TRUE(matcher_eval(disjunction));
    }

	TEST("should match false when all false in disjunctive matcher") {
		DisjunctiveMatcher disjunction;
		disjunction.add(alwaysFalse);
		disjunction.add(alwaysFalse);
        ASSERT_FALSE(matcher_eval(disjunction));
    }
};
