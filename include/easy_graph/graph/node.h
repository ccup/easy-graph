#ifndef HF37ACE88_F726_4AA3_8599_ED7A888AA623
#define HF37ACE88_F726_4AA3_8599_ED7A888AA623

#include "easy_graph/graph/node_id.h"
#include "easy_graph/infra/operator.h"
#include "easy_graph/infra/ext_traits.h"
#include <vector>
#include <any>

EG_NS_BEGIN

struct Graph;
struct GraphVisitor;

struct Node
{
    template<typename ...GRAPHS, SUBGRAPH_CONCEPT(GRAPHS, Graph)>
    Node(const NodeId& id, const GRAPHS&... graphs)
	: id(id), subgraphs{&graphs...} {
    }
    
    template<typename ...GRAPHS, SUBGRAPH_CONCEPT(GRAPHS, Graph)>
    Node(const NodeId& id, const std::any& any, const GRAPHS&... graphs)
	: id(id), any(&any), subgraphs{&graphs...} {
    }

    __DECL_COMP(Node);

    NodeId getId() const;

    void packing(const std::any& any) {
    	this->any = any;
    }

    template<typename CONTENT>
    CONTENT* unpacking() {
    	return std::any_cast<CONTENT>(&any);
    }

    void addSubgraph(const Graph&);
    void accept(GraphVisitor&) const;

private:
    NodeId id;
    std::any any;
    std::vector<const Graph*> subgraphs;
};

EG_NS_END

#endif