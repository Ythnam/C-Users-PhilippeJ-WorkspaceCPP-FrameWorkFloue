/*
 * SugenoConclusion.h
 *
 *  Created on: 28 f�vr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENOCONCLUSION_H_
#define FUZZY_SUGENOCONCLUSION_H_
#include "NaryExpression.h"
//Zi c'est lacombinaison lineaire des entr�s
//wi c'est l'evaluation de la partie ant�c�dante:
//->
namespace core{
template <class T>
class SugenoConclusion : public core::NaryExpression<T>{

public : T evaluate(core::Expression<T>**) const;

private : T* coeff;

};
}
#endif /* FUZZY_SUGENOCONCLUSION_H_ */

/*
 */
