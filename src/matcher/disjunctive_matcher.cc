#include "easy_graph/matcher/disjunctive_matcher.h"

EG_NS_BEGIN

bool DisjunktiveMatcher::eval() const {
	for (auto matcher : matchers) {
		if (matcher->eval()) return true;
	}
	return false;
}

EG_NS_END
