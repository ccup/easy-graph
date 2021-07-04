#include "easy_graph/matcher/node_id_equal_matcher.h"
#include "easy_graph/graph/node.h"

EG_NS_BEGIN

NodeIdEqualMatcher::NodeIdEqualMatcher(const Node& node, const NodeId& id)
: NodeMatcher(node), expectedId(id) {
}

bool NodeIdEqualMatcher::eval() const {
	return node.getId() == expectedId;
}

EG_NS_END
