/*
 * AndMult.h
 *
 *  Created on: 2 f�vr. 2016
 *      Author: PhilippeJ
 */

#ifndef ANDMULT_H_
#define ANDMULT_H_
#include "Core/BinaryExpression.h"


namespace fuzzy{
template <class T>
class AndMult: public fuzzy::And<T>{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template<class T>
T AndMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	T l = left->evaluate();
	T r = right->evaluate();
	return l*r;
}

}
#endif /* ANDMULT_H_ */
