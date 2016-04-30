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

public :
	virtual ~NaryShadowExpression(){};
	NaryShadowExpression();
	NaryShadowExpression(core::NaryExpression<T>*);
	T evaluate(std::vector<core::Expression<T>*>*) const;
	void setTarget(core::NaryExpression<T>*);
	core::NaryExpression<T>* getTarget() const;

private : core::NaryExpression<T>* target;

};

template<class T>
core::NaryShadowExpression<T>::NaryShadowExpression():target(){

}

template<class T>
core::NaryShadowExpression<T>::NaryShadowExpression(core::NaryExpression<T>* _target):target(_target){

}

template <class T>
T core::NaryShadowExpression<T>::evaluate(std::vector<core::Expression<T>*>* operands) const{
	if(target != NULL){
		return target->evaluate(operands);
	}
}

template<class T>
void core::NaryShadowExpression<T>::setTarget(core::NaryExpression<T>* _target){
	this->target = _target;
}

template<class T>
core::NaryExpression<T>* core::NaryShadowExpression<T>::getTarget() const{
	return this->target;
}
}




#endif /* CORE_NARYSHADOWEXPRESSION_H_ */
