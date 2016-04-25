/*
 * UnaryExpressionModel.h
 *
 *  Created on: 9 févr. 2016
 *      Author: Mathieu
 */
#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h"

namespace core {
template<class T>
class UnaryExpressionModel: public Expression<T>, public UnaryExpression<T> {

public:
	UnaryExpressionModel(UnaryExpression<T>* = NULL, Expression<T>* = NULL);
	T evaluate() const;
	T evaluate(Expression<T>*) const;

	UnaryExpression<T>* GetOperator();
	Expression<T>* GetOperand();
	void SetOperator(UnaryExpression<T>*);
	void SetOperand(Expression<T>*);

private:
	UnaryExpression<T>* ope;
	Expression<T>* operand;

};

template<class T>
UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _ope,
		Expression<T>* _operand) :
		ope(_ope), operand(_operand) {

}

template<class T>
T UnaryExpressionModel<T>::evaluate() const {

	if (operand != NULL)
		return evaluate(operand);
	return NULL;

}

template<class T>
T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const {

	if (ope != NULL)
		return ope->evaluate(o);
	return NULL;

}

template<class T>
UnaryExpression<T>* UnaryExpressionModel<T>::GetOperator() {

	return ope;

}

template<class T>
Expression<T>* UnaryExpressionModel<T>::GetOperand() {

	return operand;

}

template<class T>
void UnaryExpressionModel<T>::SetOperator(UnaryExpression<T>* _ope) {

	ope = _ope;

}

template<class T>
void UnaryExpressionModel<T>::SetOperand(Expression<T>* _operand) {

	operand = *_operand;

}
}
#endif
