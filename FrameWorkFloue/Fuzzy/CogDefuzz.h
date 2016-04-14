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
#include "Evaluator.h"
#include <vector>
#include <utility>

namespace fuzzy {
template<class T>
class CogDefuzz: public fuzzy::MamdaniDefuzz<T> {

public:
	CogDefuzz();
	virtual ~CogDefuzz() {
	}
	;
	virtual T defuzz(const typename Evaluator<T>::Shape&) const;
private:
	double min, max, step;
};
template<class T>
CogDefuzz<T>::CogDefuzz() :
		min(0), max(0), step(0) {
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
