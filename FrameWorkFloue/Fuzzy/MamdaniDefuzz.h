/*
 * MamdaniDefuzz.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef MAMDANIDEFUZZ_H_
#define MAMDANIDEFUZZ_H_

#include "../Core/BinaryExpression.h"
#include "Fuzzy/Evaluator.h"

namespace fuzzy{
template <class T>
class MamdaniDefuzz : public core::BinaryExpression{

public :
	virtual ~MamdaniDefuzz(){};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*);
	virtual T defuzz(Evaluator<T>::buildShape(const T&, const T&, const T&, core::Expression<T>& )) const = 0;

};

template <class T>
T MamdaniDefuzz<T>::evaluate(core::Expression<T>* outPutVar, core::Expression<T>* fuzzySystem){
	return defuzz(Evaluator<T>::buildShape(const T&, const T&, const T&, core::Expression<T>& ));
}
}
#endif /* MAMDANIDEFUZZ_H_ */
