#include "easy_graph/matcher/graph_name_equal_matcher.h"
#include "easy_graph/graph/graph.h"

EG_NS_BEGIN

GraphNameEqualMatcher::GraphNameEqualMatcher(const Graph& graph, const std::string& name)
: GraphMatcher(graph), expectedName(name){
}

bool GraphNameEqualMatcher::eval() const {
	return graph.getName() == expectedName;
}

EG_NS_END
