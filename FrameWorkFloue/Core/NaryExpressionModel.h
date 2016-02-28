/*
 * NaryExpressionModel.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_NARYEXPRESSIONMODEL_H_
#define CORE_NARYEXPRESSIONMODEL_H_
#include "NaryExpression.h"

namespace core{
template <class T>
class NaryExpressionModel : public core::NaryExpression<T>, public core::Expression<T>{

public : T evaluate() const;
		 T evaluate(core::Expression<T>**) const;

private : Expression* operands;
		  NaryExpression ope;
};

template <class T>
T NaryExpressionModel<T>::evaluate() const{
	if(operands != NULL){
		return evaluate(operands);
	}
}

template <class T>
T NaryExpressionModel<T>::evaluate(core::Expression<T>** op) const{
	if(ope != NULL){

		return ope->evaluate(op); // faire sur la collection
	}
	return NULL;
}

}
#endif /* CORE_NARYEXPRESSIONMODEL_H_ */
