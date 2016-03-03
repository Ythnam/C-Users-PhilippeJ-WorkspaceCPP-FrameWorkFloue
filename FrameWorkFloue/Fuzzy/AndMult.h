/*
 * AndMult.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ANDMULT_H_
#define ANDMULT_H_
#include "And.h"
#include "../Core/BinaryExpression.h"


namespace fuzzy{
template <class T>
class AndMult: public fuzzy::And<T>{

public :
	AndMult();
	virtual ~AndMult(){};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
template <class T>
	AndMult<T>::AndMult()
	{
	}
template <class T>
T AndMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	return left->evaluate() * right->evaluate();
}

}
#endif /* ANDMULT_H_ */
