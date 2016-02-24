/*
 * BinaryExpression.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_
#include "Expression.h"

namespace core{
template <class T>
class BinaryExpression{

public : virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;

};
}

template<class T>
T evaluate(core::Expression<T>* left, core::Expression<T>* right){

}
#endif /* BINARYEXPRESSION_H_ */
