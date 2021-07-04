#ifndef HD27B7A2B_EA7F_4567_B94C_01D3D8C2B53F
#define HD27B7A2B_EA7F_4567_B94C_01D3D8C2B53F

#include "easy_graph/matcher/matcher.h"

EG_NS_BEGIN

struct NegativeMatcher : Matcher {
	explicit NegativeMatcher(const Matcher&);

private:
	bool eval() const override;

private:
	const Matcher& matcher;
};

EG_NS_END

#endif
