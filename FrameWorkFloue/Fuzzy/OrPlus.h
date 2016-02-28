/*
 * OrPlus.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ORPLUS_H_
#define ORPLUS_H_
#include "Or.h"

namespace fuzzy{
template <class T>
class OrPlus : public fuzzy::Or{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template <class T>
T OrPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right)const{
	T l = left->evaluate();
	T r = right->evaluate();
	return l+r;
}
}
#endif /* ORPLUS_H_ */
