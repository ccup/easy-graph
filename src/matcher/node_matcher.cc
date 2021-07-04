#include "easy_graph/matcher/node_matcher.h"

EG_NS_BEGIN

NodeMatcher::NodeMatcher(const Node& node)
: node(node) {
}

bool NodeMatcher::eval() const {
	return false;
}

EG_NS_END
