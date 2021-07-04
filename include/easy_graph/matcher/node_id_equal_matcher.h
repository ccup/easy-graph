#ifndef H997D65E7_9F23_4509_8182_35D5179BC485
#define H997D65E7_9F23_4509_8182_35D5179BC485

#include "easy_graph/matcher/node_matcher.h"
#include "easy_graph/graph/node_id.h"

EG_NS_BEGIN

struct NodeIdEqualMatcher : NodeMatcher {
	NodeIdEqualMatcher(const Node&, const NodeId&);

private:
	bool eval() const override;

private:
	const NodeId& expectedId;
};

EG_NS_END

#endif
