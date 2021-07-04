#ifndef HFB0D4ACE_74FB_4EFD_991E_74ACF9CF0F28
#define HFB0D4ACE_74FB_4EFD_991E_74ACF9CF0F28

#include "easy_graph/matcher/matcher.h"

EG_NS_BEGIN

template<typename MATCHER>
bool matcher_eval(const MATCHER& matcher) {
	return static_cast<const Matcher&>(matcher).eval();
}

EG_NS_END

#endif
