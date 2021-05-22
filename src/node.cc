#include "node.h"

EG_NS_BEGIN

Node::Node(const std::string name)
: name(name) {
}

__DEF_EQUALS(Node)
{
	return name == rhs.name;
}

__DEF_COMP(Node)
{
	return name < rhs.name;
}

std::string Node::getName() const {
	return name;
}

EG_NS_END
