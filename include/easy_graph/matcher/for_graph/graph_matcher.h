#ifndef H0E11FF2D_D17D_4A84_8BB3_4DA7C44346AE
#define H0E11FF2D_D17D_4A84_8BB3_4DA7C44346AE

#include "easy_graph/matcher/matcher.h"

EG_NS_BEGIN

struct Graph;

struct GraphMatcher : Matcher {
	explicit GraphMatcher(const Graph&);

private:
	bool eval() const override;

protected:
	const Graph& graph;
};

EG_NS_END

#endif
