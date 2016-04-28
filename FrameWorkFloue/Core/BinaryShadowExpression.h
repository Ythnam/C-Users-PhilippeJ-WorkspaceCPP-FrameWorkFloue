/*
 * BinaryShadowExpression.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_BINARYSHADOWEXPRESSION_H_
#define CORE_BINARYSHADOWEXPRESSION_H_
#include "BinaryExpression.h"

namespace core {
template<class T>
class BinaryShadowExpression: public core::BinaryExpression<T> {

public:
	BinaryShadowExpression(core::BinaryExpression<T>* = NULL);
	void setTarget(core::BinaryExpression<T>);
	T evaluate(core::Expression<T>*, core::Expression<T>*) const;

private:
	core::BinaryExpression<T>* target;
};

template<class T>
BinaryShadowExpression<T>::BinaryShadowExpression(
		core::BinaryExpression<T>* _target) :
		target(_target) {

}

template<class T>
void BinaryShadowExpression<T>::setTarget(core::BinaryExpression<T> _target) {
	target = _target;
}

template<class T>
T BinaryShadowExpression<T>::evaluate(core::Expression<T>* left,
		core::Expression<T>* right) const {
	if (target != NULL) {
		return target->evaluate(left, right);
	}
}
}
#endif /* CORE_BINARYSHADOWEXPRESSION_H_ */
