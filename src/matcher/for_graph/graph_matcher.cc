#include "easy_graph/matcher/for_graph/graph_matcher.h"

EG_NS_BEGIN

GraphMatcher::GraphMatcher(const Graph& graph)
: graph(graph){
}

bool GraphMatcher::eval() const {
	return false;
}

EG_NS_END
