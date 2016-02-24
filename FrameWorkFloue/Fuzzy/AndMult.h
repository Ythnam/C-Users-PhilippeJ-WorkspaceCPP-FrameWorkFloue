/*
 * AndMult.h
 *
 *  Created on: 2 févr. 2016
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
}
#endif /* ANDMULT_H_ */
