#include "easy_graph/pred/concrete/linked_to.h"
#include "easy_graph/graph/edge.h"

EG_NS_BEGIN

LinkedTo::LinkedTo(const NodeId& node, const PortId* port)
: node(node), port(port){
}

bool LinkedTo::operator()(const Edge& edge) const {
	if (node != edge.getDst().getNodeId()) return false;
	return port ? *port == edge.getDst().getPortId() : true;
}

EG_NS_END
