#ifndef H9D3AF1F3_127F_4881_84F0_1B448BA25811
#define H9D3AF1F3_127F_4881_84F0_1B448BA25811

#include "easy_graph/graph/pred.h"

EG_NS_BEGIN

struct Graph;
struct Node;
struct Edge;

struct Matcher {
	Matcher& pred(const Pred<Node>*);
	Matcher& pred(const Pred<Edge>*);

	bool match(const Graph&) const;

private:
	const Pred<Node>* nodePred{nullptr};
	const Pred<Edge>* edgePred{nullptr};
};

EG_NS_END

#endif
