#ifndef HA7019144_9EA8_4982_8E71_D13B1C41730B
#define HA7019144_9EA8_4982_8E71_D13B1C41730B

#include "easy_graph/graph/pred.h"
#include "easy_graph/graph/node_id.h"
#include "easy_graph/graph/port_id.h"

EG_NS_BEGIN

struct Edge;

struct LinkedTo : Pred<Edge> {
	LinkedTo(const NodeId& node, const PortId* port = nullptr);

private:
	bool operator()(const Edge&) const override;

private:
	const NodeId& node;
	const PortId* port;
};

EG_NS_END

#endif
