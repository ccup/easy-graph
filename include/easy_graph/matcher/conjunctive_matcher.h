#ifndef HEFBE12DD_6F48_4AEE_A920_0D0416625F50
#define HEFBE12DD_6F48_4AEE_A920_0D0416625F50

#include "easy_graph/matcher/junctive_matcher.h"

EG_NS_BEGIN

struct ConjunctiveMatcher : JunctiveMatcher {
private:
	bool doEval() const override;
};

EG_NS_END

#endif
