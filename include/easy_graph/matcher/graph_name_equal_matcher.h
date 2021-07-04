#ifndef HC620DA3A_52F9_49C2_A3C1_C8013E642584
#define HC620DA3A_52F9_49C2_A3C1_C8013E642584

#include "easy_graph/matcher/graph_matcher.h"
#include <string>

EG_NS_BEGIN

struct GraphNameEqualMatcher : GraphMatcher {
	GraphNameEqualMatcher(const Graph&, const std::string&);

private:
	bool eval() const override;

private:
	const std::string& expectedName;
};

EG_NS_END

#endif
