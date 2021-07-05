#ifndef H738729B1_D1DF_41D1_96D0_36F12123B5D3
#define H738729B1_D1DF_41D1_96D0_36F12123B5D3

#include "easy_graph/infra/keywords.h"

EG_NS_BEGIN

INTERFACE(Matcher) {
	ABSTRACT(bool eval() const);
};

template<typename MATCHER>
bool matcher_eval(const MATCHER& matcher) {
	return static_cast<const Matcher&>(matcher).eval();
}

EG_NS_END

#endif
