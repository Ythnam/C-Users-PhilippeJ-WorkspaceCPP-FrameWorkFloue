/*
 * MamdaniDefuzz.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef MAMDANIDEFUZZ_H_
#define MAMDANIDEFUZZ_H_

#include "../Core/BinaryExpression.h"
#include "Evaluator.h"

namespace fuzzy {
template<class T>
class MamdaniDefuzz: public core::BinaryExpression<T> {

public:
	MamdaniDefuzz();
	MamdaniDefuzz(const T& _min, const T& _max, const T& _step);
	virtual ~MamdaniDefuzz() {
	}
	;
	virtual T evaluate(core::Expression<T>* left,
			core::Expression<T>* right) const;
	virtual T defuzz(const typename Evaluator<T>::Shape& shape) const = 0;
	void setValues(const T&, const T&, const T&);
private:
	T min, max, step;

};

template<class T>
MamdaniDefuzz<T>::MamdaniDefuzz() :
		min(0), max(0), step(0) {
}
template<class T>
MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min, const T& _max, const T& _step) :
		min(_min), max(_max), step(_step) {
}
template<class T>
T MamdaniDefuzz<T>::evaluate(core::Expression<T>* left,core::Expression<T>* right)const {

	return defuzz(Evaluator<T>::buildShape(min, max, step, left, right));
}
template<class T>
	void MamdaniDefuzz<T>::setValues(const T& _min, const T& _max, const T& _step)
	{
		min = _min;
		max = _max;
		step = _step;
	}
}
#endif /* MAMDANIDEFUZZ_H_ */
