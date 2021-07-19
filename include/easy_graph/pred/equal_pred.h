#ifndef H7C3D58DB_D006_4EDC_9E69_77D283F997F7
#define H7C3D58DB_D006_4EDC_9E69_77D283F997F7

#include "easy_graph/graph/pred.h"

EG_NS_BEGIN

template<typename T>
struct EqualPred : Pred<T> {
	EqualPred(const T& expected)
	: expected(expected) {
	}

private:
	bool operator()(const T& actual) const override {
		return expected == actual;
	}

private:
	const T& expected;
};

EG_NS_END

#endif
