#ifndef H986AC6C1_D088_4767_AFF8_F7E8DBCE681A
#define H986AC6C1_D088_4767_AFF8_F7E8DBCE681A

#include "easy_graph/matcher/junctive_matcher.h"

EG_NS_BEGIN

struct DisjunctiveMatcher : JunctiveMatcher {
private:
	bool doEval() const override;
};

EG_NS_END

#endif
