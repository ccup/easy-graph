#ifndef H986AC6C1_D088_4767_AFF8_F7E8DBCE681A
#define H986AC6C1_D088_4767_AFF8_F7E8DBCE681A

#include "easy_graph/matcher/matcher.h"
#include <vector>

EG_NS_BEGIN

struct DisjunktiveMatcher : Matcher {
	template<typename ...MATCHER>
	explicit DisjunktiveMatcher(MATCHER && ...matcher) {
		(matchers.emplace_back(std::forward<MATCHER>(&matcher)), ...);
	}

private:
	bool eval() const override;

private:
	std::vector<const Matcher*> matchers;
};

EG_NS_END

#endif
