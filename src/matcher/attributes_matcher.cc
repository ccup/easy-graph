#include "easy_graph/matcher/attributes_matcher.h"

EG_NS_BEGIN

AttributesMatcher::AttributesMatcher(const AttributesMixin& attrs)
: attrs(attrs) {
}

bool AttributesMatcher::eval() const {
	return false;
}

EG_NS_END