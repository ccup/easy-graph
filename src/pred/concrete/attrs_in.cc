#include "easy_graph/pred/concrete/attrs_in.h"
#include "easy_graph/attribute/attributes.h"

EG_NS_BEGIN

void AttrsIn::add(const std::string& key) {
	expectedAttrs.push_back(key);
}

bool AttrsIn::operator()(const Attributes& actual) const {
	for (const auto& key : expectedAttrs) {
		if (!actual.get(key)) return false;
	}
	return true;
}

EG_NS_END
