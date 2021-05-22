#include "chain_builder.h"
#include "graph.h"
#include "edge.h"

EG_NS_BEGIN

ChainBuilder::ChainBuilder(Graph& graph, EdgeType type)
: graph(graph),
  nodeFromEgde(*this, type) {
}

ChainBuilder::ChainNodeBuilder* ChainBuilder::operator->() {
	return &nodeFromEgde;
}

ChainBuilder& ChainBuilder::addDstNodeOnEdge(const Node& node, EdgeType type) {
	Node* current_node = graph.addNode(node);
	if (lastNode) {
		graph.addEdge(Edge(type, *lastNode, *current_node));
	}
	lastNode = current_node;
	return *this;
}

ChainBuilder::ChainNodeBuilder::ChainNodeBuilder(ChainBuilder& chain, EdgeType edgeType)
: chain(chain), edgeType(edgeType) {
}

ChainBuilder& ChainBuilder::ChainNodeBuilder::NODE(const Node& node) {
	return chain.addDstNodeOnEdge(node, edgeType);
}

EG_NS_END
