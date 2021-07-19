#ifndef H2FBC733E_27C2_4755_B05E_50DFA4ED47F9
#define H2FBC733E_27C2_4755_B05E_50DFA4ED47F9

#include "easy_graph/graph/pred.h"

EG_NS_BEGIN

template<typename T>
struct NotPred : Pred<T> {
	NotPred(const Pred<T> pred)
	: pred(pred) {
	}

private:
	bool operator()(const T& actual) const override {
		return !pred(actual);
	}

private:
	const Pred<T> pred;
};

EG_NS_END

#endif
