#ifndef HD926D39D_1341_4369_A4DD_906B4A09EF0B
#define HD926D39D_1341_4369_A4DD_906B4A09EF0B

#include "easy_graph/graph/pred.h"
#include "easy_graph/attribute/attribute.h"
#include <list>

EG_NS_BEGIN

struct Attributes;

struct AttrsIn: Pred<Attributes> {
	void add(const std::string& key);

private:
	bool operator()(const Attributes&) const override;

private:
	std::list<AttrKey> expectedAttrs;
};

EG_NS_END

#endif
