/*
 * BinaryExpressionModel.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef BINARYEXPRESSIONMODEL_H_
#define BINARYEXPRESSIONMODEL_H_
#include "BinaryExpression.h"

namespace core{
template <class T>
class BinaryExpressionModel : public core::Expression<T>, core::BinaryExpression<T>{

private : core::BinaryExpression oper;
		  core::Expression left, right;

public : virtual T evaluate() const;
		 virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template <class T>
T evaluate(Expression l, Expression r) const{
	if(oper != null){
		return oper.evaluate(l,r);
	}
}

}
#endif /* BINARYEXPRESSIONMODEL_H_ */

