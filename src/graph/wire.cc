#include "easy_graph/graph/wire.h"

EG_NS_BEGIN

Wire::Wire(const Endpoint& endpoint, const PortId& port)
: endpoint(endpoint), port(port) {
}

__DEF_EQUALS(Wire)
{
	return  (endpoint == rhs.endpoint) && (port == rhs.port);
}

__DEF_COMP(Wire)
{
	return std::tie(endpoint, port) < std::tie(rhs.endpoint, rhs.port);
}

Endpoint Wire::getEndpoint() const {
	return endpoint;
}

PortId Wire::getPortId() const {
	return port;
}

EG_NS_END
