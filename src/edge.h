#ifndef HE62943BF_1F7C_4EF9_B306_D9C94634EA74
#define HE62943BF_1F7C_4EF9_B306_D9C94634EA74

#include "edge_type.h"
#include "node_port.h"
#include "cmp_helper.h"
#include "layoutable.h"
#include <string>

EG_NS_BEGIN

struct Edge : Layoutable
{
	Edge(const EdgeType type,
		 const std::string& label,
		 const NodePort& src,
		 const NodePort& dst);

	__DECL_COMP(Edge);

private:
	std::string getLayout(const LayoutOption&) const override;

private:
	std::string label;
	EdgeType type;

	NodePort src;
	NodePort dst;
};

EG_NS_END

#endif
