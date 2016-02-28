/*
 * BinaryExpressionModel.h
 *
 *  Created on: 9 f�vr. 2016
 *      Author: Mathieu
 */
#ifndef BinaryExpressionModel_H
#define BinaryExpressionModel_H
#include "BinaryExpression.h"


namespace core
{

	template <class T>
	class BinaryExpressionModel:public core::Expression<T>, public core::BinaryExpression<T>
	{

	public:
		BinaryExpressionModel(core::BinaryExpression<T>* =NULL, core::Expression<T>* =NULL);

		T evaluate() const;
		T evaluate(core::Expression<T>*, core::Expression<T>*) const;

		core::BinaryExpression<T>* GetOperator();
		core::Expression<T>* GetOperand();
		void SetOperator(core::BinaryExpression<T>*);
		void SetOperand(core::Expression<T>*);


	private :
		BinaryExpression<T>* ope;
		Expression<T>* operand;

	};

	template <class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _ope, Expression<T>* _operand):
	ope(_ope),operand(_operand)
	{}

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if ( operand!=NULL)
			return evaluate(operand);
		return NULL;
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l,Expression<T>* r) const
	{
		if (ope!=NULL)
		{
			return ope->evaluate(r);
			return ope->evaluate(l);
		}
		return NULL;
	}

	template <class T>
	BinaryExpression<T>* BinaryExpressionModel<T>::GetOperator()
	{
		return ope;
	}

	template <class T>
	Expression<T>* BinaryExpressionModel<T>::GetOperand()
	{
		return operand;
	}

	template <class T>
	void BinaryExpressionModel<T>::SetOperator(BinaryExpression<T>* _ope)
	{
		ope=*_ope;
	}

	template <class T>
	void BinaryExpressionModel<T>::SetOperand(Expression<T>* _operand)
	{
		operand=*_operand
	}

}
#endif
