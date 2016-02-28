/*
 * ThenMult.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef THENMULT_H_
#define THENMULT_H_
#include "Then.h"

namespace fuzzy{
template <class T>
class ThenMult : public fuzzy::Then{

public : T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template <class T>
T ThenMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	return left->evaluate() * right->evaluate();
}
}
#endif /* THENMULT_H_ */
