#include "easy_graph/matcher/conjunctive_matcher.h"

EG_NS_BEGIN

bool ConjunctiveMatcher::doEval() const {
	for (auto matcher : matchers) {
		if (!matcher->eval()) return false;
	}
	return true;
}

EG_NS_END
