#ifndef HA69CB619_7DF2_4177_AE1C_D8F86B9CA67D
#define HA69CB619_7DF2_4177_AE1C_D8F86B9CA67D

#include "easy_graph/matcher/matcher.h"

EG_NS_BEGIN

struct AttributesMixin;

struct AttributesMatcher : Matcher {
	explicit AttributesMatcher(const AttributesMixin&);

private:
	bool eval() const override;

protected:
	const AttributesMixin& attrs;
};

EG_NS_END

#endif
