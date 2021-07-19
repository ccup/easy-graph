#ifndef H848D1B46_14DC_4A66_A4BC_B8E98AEE9BCC
#define H848D1B46_14DC_4A66_A4BC_B8E98AEE9BCC

#include "easy_graph/graph/pred.h"
#include <list>

EG_NS_BEGIN

template<typename T>
struct Preds : Pred<T> {
	void add(const Pred<T>& pred) {
		preds.push_back(&pred);
	}

private:
	bool operator()(const T& actual) const override {
		return pred(actual);
	}

private:
	ABSTRACT(bool pred(const T&) const);

private:
	std::list<const Pred<T>*> preds;
};

EG_NS_END

#endif
