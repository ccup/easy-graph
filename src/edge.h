#ifndef HE62943BF_1F7C_4EF9_B306_D9C94634EA74
#define HE62943BF_1F7C_4EF9_B306_D9C94634EA74

#include "easy_graph/eg.h"
#include "edge_type.h"
#include "cmp_helper.h"

EG_NS_BEGIN

struct Node;

struct Edge {
	Edge(const EdgeType type, const Node& src, const Node& dst);
	__DECL_COMP(Edge);

	EdgeType getType() const;
	const Node& getSrcNode() const;
	const Node& getDstNode() const;

private:
	EdgeType type;
	const Node& src;
	const Node& dst;
};

EG_NS_END

#endif
