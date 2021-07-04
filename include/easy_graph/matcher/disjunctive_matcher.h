#ifndef H986AC6C1_D088_4767_AFF8_F7E8DBCE681A
#define H986AC6C1_D088_4767_AFF8_F7E8DBCE681A

#include "easy_graph/matcher/matcher.h"
#include <vector>

EG_NS_BEGIN

struct DisjunctiveMatcher : Matcher {
	void add(const Matcher&);

private:
	bool eval() const override;

private:
	std::vector<const Matcher*> matchers;
};

EG_NS_END

#endif
