#ifndef HEFBE12DD_6F48_4AEE_A920_0D0416625F50
#define HEFBE12DD_6F48_4AEE_A920_0D0416625F50

#include "easy_graph/matcher/matcher.h"
#include <vector>

EG_NS_BEGIN

struct ConjunctiveMatcher : Matcher {
	void add(const Matcher&);

private:
	bool eval() const override;

private:
	std::vector<const Matcher*> matchers;
};


EG_NS_END

#endif
