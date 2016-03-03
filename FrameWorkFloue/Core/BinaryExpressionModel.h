/*
 * BinaryExpressionModel.h
 *
 *  Created on: 9 févr. 2016
 *      Author: Mathieu GALLIERE
 */
#ifndef BinaryExpressionModel_H
#define BinaryExpressionModel_H
#include "BinaryExpression.h"


namespace core
{

template <class T>
class BinaryExpressionModel:public Expression<T>,public BinaryExpression<T>
{

public :
	BinaryExpressionModel(BinaryExpression<T>* =NULL,Expression<T>* =NULL, Expression<T>* =NULL);
	~BinaryExpressionModel(){};

	Expression<T>* GetLeft() const;
	Expression<T>* GetRight() const;
	BinaryExpression<T>* GetOperator();
	void SetLeft(Expression<T>*);
	void SetRight(Expression<T>*);
	void SetOperator(BinaryExpression<T>*);

	T evaluate() const;
	T evaluate(Expression<T>*, Expression<T>*) const;

private :
	Expression<T>* left;
	Expression<T>* right;
	BinaryExpression<T>* ope;

};




template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _ope,Expression<T>* _left, Expression<T>* _right):
ope(_ope),left(_left),right(_right)
{}

template <class T>
Expression<T>* BinaryExpressionModel<T>::GetLeft() const
{
	return left;
}

template <class T>
Expression<T>* BinaryExpressionModel<T>::GetRight() const
{
	return right;
}

template <class T>
BinaryExpression<T>* BinaryExpressionModel<T>::GetOperator()
{
	return ope;
}

template <class T>
void BinaryExpressionModel<T>::SetLeft(Expression<T> *_left)
{
	left=*_left;
}

template <class T>
void BinaryExpressionModel<T>::SetRight(Expression<T>* _right)
{
	right=*_right;
}

template <class T>
void BinaryExpressionModel<T>::SetOperator(BinaryExpression<T>* _ope)
{
	ope=_ope;
}

template <class T>
T BinaryExpressionModel<T>::evaluate() const
{
	if (left!=NULL && right!=NULL)
		return evaluate(left, right);
	return NULL;
}

template <class T>
T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
{
	if (ope!=NULL)
		return ope->evaluate(l, r);
	return NULL;
}

}

#endif
