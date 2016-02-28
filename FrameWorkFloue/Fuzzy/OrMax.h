/*
 * OrMax.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ORMAX_H_
#define ORMAX_H_
#include "Or.h"

namespace fuzzy{
template <class T>
class OrMax: public fuzzy::Or{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template <class T>
T OrMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	T l = left->evaluate();
	T r = right->evaluate();
	return (l >= r) ? l : r;
}

}
#endif /* ORMAX_H_ */
