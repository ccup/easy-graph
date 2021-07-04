#include "easy_graph/matcher/conjunctive_matcher.h"

EG_NS_BEGIN

void ConjunctiveMatcher::add(const Matcher& matcher) {
	matchers.push_back(&matcher);
}

bool ConjunctiveMatcher::eval() const {
	if (!matchers.size()) return false;

	for (auto matcher : matchers) {
		if (!matcher->eval()) return false;
	}
	return true;
}

EG_NS_END
