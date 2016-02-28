/*
 * NaryShadowExpression.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_NARYSHADOWEXPRESSION_H_
#define CORE_NARYSHADOWEXPRESSION_H_
#include "NaryExpression.h"

namespace core{
template <class T>
class NaryShadowExpression : public core::NaryExpression<T>{

public : T evaluate(core::Expression<T>**) const;

private : NaryExpression target;

};

template <class T>
T NaryShadowExpression<T>::evaluate(core::Expression<T>** operands) const{
	if(target != NULL){
		return target.evaluate(operands);
	}
}
}




#endif /* CORE_NARYSHADOWEXPRESSION_H_ */
