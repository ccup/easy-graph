#include "easy_graph/graph/endpoint.h"

EG_NS_BEGIN

Endpoint::Endpoint(const NodeId& nodeId, const PortId& portId)
: nodeId(nodeId), portId(portId) {
}

__DEF_EQUALS(Endpoint)
{
	return  (nodeId == rhs.nodeId) && (portId == rhs.portId);
}

__DEF_COMP(Endpoint)
{
	return std::tie(nodeId, portId) < std::tie(rhs.nodeId, rhs.portId);
}

NodeId Endpoint::getNodeId() const {
	return nodeId;
}

PortId Endpoint::getPortId() const {
	return portId;
}

EG_NS_END
