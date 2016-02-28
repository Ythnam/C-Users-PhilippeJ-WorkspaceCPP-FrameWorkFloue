/*
 * NaryExpression.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_NARYEXPRESSION_H_
#define CORE_NARYEXPRESSION_H_
#include "Expression.h"

namespace core{
template <class T>
class NaryExpression<T>{

public : T evaluate(core::Expression<T>**) const = 0;

};
}
#endif /* CORE_NARYEXPRESSION_H_ */
