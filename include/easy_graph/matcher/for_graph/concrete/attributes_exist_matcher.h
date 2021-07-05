#ifndef H5619987C_F849_4411_B8E6_E0C956E51729
#define H5619987C_F849_4411_B8E6_E0C956E51729

#include "easy_graph/matcher/for_graph/attributes_matcher.h"
#include "easy_graph/attribute/attributes.h"

EG_NS_BEGIN

struct AttributesExistMatcher : AttributesMatcher {
	template<typename ...ATTR>
	explicit AttributesExistMatcher(const AttributesMixin& attrs, ATTR && ...expects)
	: AttributesMatcher(attrs) {
		(expectedAttrs.set(std::forward<ATTR>(expects)), ...);
	}

private:
	bool eval() const override;

private:
	Attributes expectedAttrs;
};

EG_NS_END

#endif
