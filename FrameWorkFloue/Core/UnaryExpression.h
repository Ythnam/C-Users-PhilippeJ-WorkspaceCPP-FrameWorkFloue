/*
 * UnaryExpression.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_
#include "Expression.h"

namespace core {
template<class T>
class UnaryExpression {

public:
	virtual ~UnaryExpression() {
	}
	;
	virtual T evaluate(Expression<T>*) const=0;

};
}
#endif /* UNARYEXPRESSION_H_ */
