#ifndef H03140D61_E359_4B7B_98AE_719BD1118E10
#define H03140D61_E359_4B7B_98AE_719BD1118E10

#include "easy_graph/matcher/matcher.h"
#include <list>

EG_NS_BEGIN

struct JunctiveMatcher : Matcher {
	void add(const Matcher&);

private:
	bool eval() const override;

private:
	ABSTRACT(bool doEval() const);

protected:
	std::list<const Matcher*> matchers;
};

EG_NS_END

#endif
