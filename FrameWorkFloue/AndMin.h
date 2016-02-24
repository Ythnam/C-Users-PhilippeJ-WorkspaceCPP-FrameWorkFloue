/*
 * AndMin.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ANDMIN_H_
#define ANDMIN_H_
#include "BinaryExpression.h"
#include "Expression.h"

namespace fuzzy{
template <class T>
class AndMin: public fuzzy::And<T>{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template<class T>
T AndMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	T l = left->evaluate();
	T r = right->evaluate();
	return (l==r) ? l : r;
}
}
#endif /* ANDMIN_H_ */
