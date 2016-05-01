/*
 * UnaryShadowExpression.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef UNARYSHADOWEXPRESSION_H_
#define UNARYSHADOWEXPRESSION_H_
#include "UnaryExpression.h"
#include <iostream>

namespace core {
template<class T>
class UnaryShadowExpression: public core::UnaryExpression<T> {

private:
	core::UnaryExpression<T>* target;

public:

	UnaryShadowExpression(core::UnaryExpression<T>* = NULL);
	virtual ~UnaryShadowExpression(){};
	void setTarget(core::UnaryExpression<T>* );
	UnaryExpression<T>* getTarget() const;
	T evaluate(core::Expression<T>*) const;

};

template<class T>
UnaryShadowExpression<T>::UnaryShadowExpression(
		core::UnaryExpression<T>* _target) :
		target(_target) {

}
template<class T>
void UnaryShadowExpression<T>::setTarget(core::UnaryExpression<T>* _target) {
	target = _target;
}

template<class T>
UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const {
	return target;
}
template<class T>
T UnaryShadowExpression<T>::evaluate(core::Expression<T>* o) const {

	return target->evaluate(o);

}
}
#endif /* UNARYSHADOWEXPRESSION_H_ */
