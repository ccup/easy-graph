#include "easy_graph/graph/node.h"
#include "easy_graph/graph/subgraph_visitor.h"
#include "easy_graph/infra/container_eq.h"

EG_NS_BEGIN

Node::Node(const NodeId& id) : id(id) {
}

__DEF_EQUALS(Node)
{
	if (id != rhs.id) return false;
	return container_is_equal(subgraphs, rhs.subgraphs);
}

__DEF_COMP(Node)
{
	return id < rhs.id;
}

NodeId Node::getId() const {
	return id;
}

void Node::accept(SubgraphVisitor& visitor) const {
	std::for_each(subgraphs.cbegin(), subgraphs.cend(),  [&visitor](const auto& subgraph){visitor.visit(subgraph);});
}

EG_NS_END
