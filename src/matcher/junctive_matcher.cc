#include "easy_graph/matcher/junctive_matcher.h"

EG_NS_BEGIN

void JunctiveMatcher::add(const Matcher& matcher) {
	matchers.push_back(&matcher);
}

bool JunctiveMatcher::eval() const {
	if (!matchers.size()) return false;
	return this->doEval();
}

EG_NS_END
