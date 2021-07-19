#ifndef HE4872B4D_0884_4721_96FE_5DA6D644DC8B
#define HE4872B4D_0884_4721_96FE_5DA6D644DC8B

#include "easy_graph/graph/pred.h"
#include "easy_graph/graph/node_id.h"
#include "easy_graph/graph/port_id.h"

EG_NS_BEGIN

struct Edge;

struct LinkedFrom : Pred<Edge> {
	LinkedFrom(const NodeId& node, const PortId* port = nullptr);

private:
	bool operator()(const Edge&) const override;

private:
	const NodeId& node;
	const PortId* port;
};

EG_NS_END

#endif
