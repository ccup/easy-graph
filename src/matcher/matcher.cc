#include "easy_graph/matcher/matcher.h"
#include "easy_graph/graph/graph.h"

EG_NS_BEGIN

Matcher& Matcher::pred(const Pred<Node>* nodePred) {
	this->nodePred = nodePred;
	return *this;
}

Matcher& Matcher::pred(const Pred<Edge>* edgePred) {
	this->edgePred = edgePred;
	return *this;
}

bool Matcher::match(const Graph& graph) const {
	if (nodePred) {
		if (graph.findNodesBy(*nodePred).empty()) return false;
	}
	if (edgePred) {
		if (graph.findEdgesBy(*edgePred).empty()) return false;
	}
	return true;
}

EG_NS_END
