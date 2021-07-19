#ifndef H36839DDE_972A_48D5_97B0_0879EEA5B741
#define H36839DDE_972A_48D5_97B0_0879EEA5B741

#include "easy_graph/pred/preds.h"

EG_NS_BEGIN

template<typename T>
struct AnyPreds : Preds<T> {
private:
	bool pred(const T& actual) const override {
		for (auto pred : preds) {
			if (pred(actual)) return true;
		}
		return false;
	}
};

EG_NS_END

#endif
