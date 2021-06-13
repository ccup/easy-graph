#ifndef HF37ACE88_F726_4AA3_8599_ED7A888AA623
#define HF37ACE88_F726_4AA3_8599_ED7A888AA623

#include "easy_graph/graph/node_id.h"
#include "easy_graph/infra/operator.h"
#include "easy_graph/graph/subgraph.h"
#include "easy_graph/attribute/attributes_mixin.h"
#include "easy_graph/graph/box.h"
#include <type_traits>
#include <vector>

EG_NS_BEGIN

struct SubgraphVisitor;

struct Node : AttributesMixin
{
	template<typename ...TS>
	Node(const NodeId& id, TS && ...ts) : id(id) {
		makeNode(std::forward<TS>(ts)...);
	}

	template<typename T, typename ... TS>
	void makeNode(T && t, TS && ...ts) {
		if constexpr (std::is_same_v<Subgraph, std::decay_t<T>>) {
			this->addSubgraph(std::forward<T>(t));
		} else if constexpr (std::is_same_v<BoxPtr, std::decay_t<T>>) {
			this->packing(std::forward<T>(t));
		} else if constexpr (std::is_same_v<Attribute, std::decay_t<T>>) {
			this->setAttr(std::forward<T>(t));
		} else if constexpr (std::is_same_v<Attributes, std::decay_t<T>>) {
			this->mergeAttrs(std::forward<T>(t));
		} else {
			static_assert(!sizeof(T), "Unsupported node construction type!");
		}
		this->makeNode(std::forward<TS>(ts)...);
	}

    __DECL_COMP(Node);

    NodeId getId() const;

    Node& packing(const BoxPtr&);

    template<typename ANYTHING>
    ANYTHING* unpacking() const {
    	if(!box) return nullptr;
    	return box_unpacking<ANYTHING>(box);
    }

    Node& addSubgraph(const Subgraph&);
    bool hasSubgraph() const;

    void accept(SubgraphVisitor&) const;

private:

    void makeNode() {}

private:
    NodeId id;
    BoxPtr box;
    std::vector<Subgraph> subgraphs;
};

EG_NS_END

#endif
