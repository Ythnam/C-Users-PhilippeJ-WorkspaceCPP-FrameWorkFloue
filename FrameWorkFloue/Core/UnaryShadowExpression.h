/*
 * UnaryShadowExpression.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef UNARYSHADOWEXPRESSION_H_
#define UNARYSHADOWEXPRESSION_H_
#include "UnaryExpression.h"

namespace core{
template <class T>
class UnaryShadowExpression : public core::UnaryExpression<T>{

private : core::UnaryExpression target;

public : UnaryShadowExpression(core::UnaryExpression<T>* = NULL);
		 T evaluate(core::Expression<T>*) const;

};

template <class T>
UnaryShadowExpression<T>::UnaryShadowExpression(core::UnaryExpression<T>* _target):target(_target){

}

template <class T>
T UnaryShadowExpression<T>::evaluate(core::Expression<T>* o)const{
	if(target != NULL){
		return target.evaluate(o);
	}
}
}
#endif /* UNARYSHADOWEXPRESSION_H_ */
