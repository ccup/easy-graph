#include "easy_graph/matcher/negative_matcher.h"

EG_NS_BEGIN

NegativeMatcher::NegativeMatcher(const Matcher& matcher)
: matcher(matcher){
}

bool NegativeMatcher::eval() const {
	return not matcher.eval();
}

EG_NS_END
