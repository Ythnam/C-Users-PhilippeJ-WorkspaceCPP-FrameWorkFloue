/*
 * Evaluator.h
 *
 *  Created on: 3 mars 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_EVALUATOR_H_
#define FUZZY_EVALUATOR_H_

#include <vector>
#include <utility>
#include "../Core/Expression.h"

using namespace std;
namespace fuzzy {
template<class T>
class Evaluator {
public:
	typedef pair<vector<T>, vector<T> > Shape;
	static Shape buildShape(const T& min, const T& max, const T& step,
			core::Expression<T>* l, core::Expression<T>* r);

	template<class U>
	class EvalFunc {

	public:
		virtual T operator ()(const T&)=0;

	};

};

template<class T>
typename Evaluator<T>::Shape Evaluator<T>::buildShape(const T& min,
		const T& max, const T& step,core::Expression<T>* l, core::Expression<T>* r) {
	vector<T> x, y;
	for (T i = min; i <= max; i += step) {

		x.push_back(i);
		y.push_back(r->evaluate());
	}
	return Shape(x, y);
}
}

#endif /* FUZZY_EVALUATOR_H_ */
