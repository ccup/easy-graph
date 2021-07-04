#include "easy_graph/matcher/disjunctive_matcher.h"

EG_NS_BEGIN

void DisjunctiveMatcher::add(const Matcher& matcher) {
	matchers.push_back(&matcher);
}

bool DisjunctiveMatcher::eval() const {
	if (!matchers.size()) return false;

	for (auto matcher : matchers) {
		if (matcher->eval()) return true;
	}
	return false;
}

EG_NS_END
