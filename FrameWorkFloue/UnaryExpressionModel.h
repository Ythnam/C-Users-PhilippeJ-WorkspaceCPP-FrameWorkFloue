/*
 * UnaryExpressionModel.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef UNARYEXPRESSIONMODEL_H_
#define UNARYEXPRESSIONMODEL_H_

namespace core{
template <class T>
class UnaryExpressionModel : public core::Expression<T>, core::UnaryExpression<T>{

private : UnaryExpression<T> oper;
		  Expression<T> operand;

public : T evaluate();
		 T evaluate(Expression);

};

template <class T>
T evaluate(){
	if(operand != null){
		return evaluate(operand);
	}
}

template <class T>
T evaluate(Expression o){
	if(oper != null){
		return oper.evaluate(operand);
	}
}
}
#endif /* UNARYEXPRESSIONMODEL_H_ */
