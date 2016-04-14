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

namespace fuzzy{
template <class T>
class MamdaniDefuzz : public core::BinaryExpression<T>{

public :
	virtual ~MamdaniDefuzz(){};
	virtual T evaluate(const T& min, const T& max, const T& step, core::Expression<T>*);
	virtual T defuzz(const typename Evaluator<T>::Shape&) const = 0;

};

}
#endif /* MAMDANIDEFUZZ_H_ */
