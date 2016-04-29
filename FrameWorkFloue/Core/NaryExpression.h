/*
 * NaryExpression.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_NARYEXPRESSION_H_
#define CORE_NARYEXPRESSION_H_
#include "Expression.h"
#include <vector>

namespace core{
template <class T>
class NaryExpression{

public :
	virtual ~NaryExpression(){};
	virtual T evaluate(std::vector<core::Expression<T>*>) const = 0;

};
}
#endif /* CORE_NARYEXPRESSION_H_ */
