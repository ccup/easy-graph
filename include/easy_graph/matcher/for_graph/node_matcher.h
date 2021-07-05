#ifndef H9317A596_D177_4719_9121_568E794EA7EC
#define H9317A596_D177_4719_9121_568E794EA7EC

#include "easy_graph/matcher/matcher.h"

EG_NS_BEGIN

struct Node;

struct NodeMatcher : Matcher {
	explicit NodeMatcher(const Node&);

private:
	bool eval() const override;

protected:
	const Node& node;
};

EG_NS_END

#endif
