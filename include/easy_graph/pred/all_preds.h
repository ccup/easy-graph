#ifndef HF9DFD33B_CA0E_4B09_8BAB_6F599BECC4FE
#define HF9DFD33B_CA0E_4B09_8BAB_6F599BECC4FE

#include "easy_graph/pred/preds.h"

EG_NS_BEGIN

template<typename T>
struct AllPreds : Preds<T> {
private:
	bool pred(const T& actual) const override {
		for (auto pred : preds) {
			if (!pred(actual)) return false;
		}
		return true;
	}
};

EG_NS_END

#endif
