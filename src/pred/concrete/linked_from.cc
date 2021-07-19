#include "easy_graph/pred/concrete/linked_from.h"
#include "easy_graph/graph/edge.h"

EG_NS_BEGIN

LinkedFrom::LinkedFrom(const NodeId& node, const PortId* port)
: node(node), port(port){
}

bool LinkedFrom::operator()(const Edge& edge) const {
	if (node != edge.getSrc().getNodeId()) return false;
	return port ? *port == edge.getSrc().getPortId() : true;
}

EG_NS_END
