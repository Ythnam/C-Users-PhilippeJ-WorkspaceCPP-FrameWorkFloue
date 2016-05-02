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

public :
	virtual ~BinaryExpression(){};
	virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;

};
}
#endif /* BINARYEXPRESSION_H_ */
