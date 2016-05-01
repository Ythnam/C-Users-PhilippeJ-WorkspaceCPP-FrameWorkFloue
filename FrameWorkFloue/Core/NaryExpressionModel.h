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

public :
	virtual ~NaryExpressionModel(){};
	NaryExpressionModel();
	NaryExpressionModel(std::vector<core::Expression<T>*>*, NaryExpression<T>*);
	T evaluate() const;
	T evaluate(std::vector<core::Expression<T>*>*) const;

private : std::vector<core::Expression<T>*>* operands;
		  NaryExpression<T>* ope;
};

template<class T>
core::NaryExpressionModel<T>::NaryExpressionModel():operands(),ope(){

}

template<class T>
core::NaryExpressionModel<T>::NaryExpressionModel(std::vector<core::Expression<T>*>* _operands, NaryExpression<T>* _ope):
operands(_operands), ope(_ope){

}

template <class T>
T core::NaryExpressionModel<T>::evaluate() const{
	if(operands != NULL){
		return evaluate(operands);
	}
}

template <class T>
T core::NaryExpressionModel<T>::evaluate(std::vector<core::Expression<T>*>* op) const{
	if(ope != NULL){

		return ope->evaluate(op); // faire sur la collection
	}
	return NULL;
}

}
#endif /* CORE_NARYEXPRESSIONMODEL_H_ */
