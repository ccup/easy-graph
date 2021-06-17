#ifndef H64ABDCBB_7F9D_4D7B_ABC1_BA3AC7DC3B8F
#define H64ABDCBB_7F9D_4D7B_ABC1_BA3AC7DC3B8F

#include "easy_graph/modifier/revise.h"
#include <vector>

EG_NS_BEGIN

struct Graph;
enum class Status;

struct GraphModifier {
	GraphModifier(Graph&);

	template<typename REVISE>
	GraphModifier& addRevise(REVISE && revise) {
		revises.emplace_back(std::forward<REVISE>(revise));
		return *this;
	}

	Status commit();
	void clear();

private:
	Graph& graph;
	std::vector<Revise> revises;
};

EG_NS_END

#endif
