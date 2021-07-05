#include "easy_graph/matcher/for_graph/concrete/attributes_exist_matcher.h"
#include "easy_graph/attribute/attributes_mixin.h"
#include "easy_graph/attribute/attribute_visitor.h"

EG_NS_BEGIN

namespace {
	struct AttributeExistVisitor : AttributeVisitor {
		AttributeExistVisitor(const AttributesMixin& attrs)
		: attrs(attrs) {
		}

		bool getResult() const {
			return result;
		}

	private:
		void visit(const Attribute& attr) override {
			const std::any* value = attrs.getAny(attr.first);
//			if ((!value) || (*value != attr.second)) {
			if (!value) {
				result = false;
				return;
			}
		}

	private:
		const AttributesMixin& attrs;
		bool  result{true};
	};
}

bool AttributesExistMatcher::eval() const {
	AttributeExistVisitor visitor(attrs);
	expectedAttrs.accept(visitor);
	return visitor.getResult();
}

EG_NS_END
