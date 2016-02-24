/*
 * UnaryShadowExpression.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef UNARYSHADOWEXPRESSION_H_
#define UNARYSHADOWEXPRESSION_H_

template <class T>
class UnaryShadowExpression : public UnaryExpression{

private : UnaryExpression target;

public : T evaluate(Expression);
};

template <class T>
T evaluate(Expression o){
	if(target != null){
		return target.evaluate(o);
	}
}

#endif /* UNARYSHADOWEXPRESSION_H_ */
