/*
 * CogDefuzz.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_
#include "../Core/BinaryExpression.h"
#include "MamdaniDefuzz.h"
#include <vector>
#include <utility>

namespace fuzzy {
template<class T>
class CogDefuzz: virtual public fuzzy::MamdaniDefuzz<T> {

public:
	CogDefuzz();
	CogDefuzz(T min_,T max_,T step_);
	virtual ~CogDefuzz(){};
	virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
	virtual T defuzz(const typename Evaluator<T>::Shape& shape) const;
private:
	double min, max, step;
};
template<class T>
CogDefuzz<T>::CogDefuzz() :
min(0), max(0), step(0) {
}
template<class T>
CogDefuzz<T>::CogDefuzz(T min_,T max_,T step_) :
min(min_), max(max_), step(step_) {
}
template<class T>
//fonction faite avec de l'aide : https://github.com/Commortel
T CogDefuzz<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{
	return defuzz(Evaluator<T>::buildShape(min, max, step, (core::ValueModel<T> *) left, right));
}
template<class T>
T CogDefuzz<T>::defuzz(const typename Evaluator<T>::Shape& shape) const {
	T firstSum = 0, secondSum = 0;
	// calcul du barycentre
	for (T i = min; i < max; i += step) {
		firstSum += shape.second.at(i) * shape.first.at(i);


		secondSum += shape.second.at(i);
	}

	T resultat = firstSum / secondSum;

	return resultat;
}
}
//algorithm.h
#endif /* COGDEFUZZ_H_ */
