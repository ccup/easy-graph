#ifndef H0FBD7838_F7B9_4B18_8FD0_4C98F1D7DBD6
#define H0FBD7838_F7B9_4B18_8FD0_4C98F1D7DBD6

#include "easy_graph/infra/keywords.h"

EG_NS_BEGIN

template<typename T>
struct Pred {
	ABSTRACT(bool operator()(const T&) const);
	virtual ~Pred() {}
};

EG_NS_END

#endif
