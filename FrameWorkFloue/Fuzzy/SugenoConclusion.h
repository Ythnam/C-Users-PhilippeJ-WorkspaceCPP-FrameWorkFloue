/*
 * SugenoConclusion.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENOCONCLUSION_H_
#define FUZZY_SUGENOCONCLUSION_H_
#include "NaryExpression.h"

namespace core{
template <class T>
class SugenoConclusion : public core::NaryExpression<T>{

public : T evaluate(core::Expression<T>*[]) const;

private : T* coeff;

};
}
#endif /* FUZZY_SUGENOCONCLUSION_H_ */
