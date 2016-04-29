/*
 * ExpressionFactory.h
 *
 *  Created on: 29 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_EXPRESSIONFACTORY_H_
#define CORE_EXPRESSIONFACTORY_H_
#include <set>
#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"

namespace core {
template<class T>
class ExpressionFactory {

public:
	ExpressionFactory();
	virtual ~ExpressionFactory();
	core::Expression<T>* Hold(core::Expression<T>*) const;
	core::Expression<T>* newUnary(core::UnaryExpression<T>*,
			core::Expression<T>*);
	core::Expression<T>* newBinary(core::BinaryExpression<T>*,
			core::Expression<T>*, core::Expression<T>*);

private:
	std::set<Expression<T> *> * memory;
};

template<class T>
core::ExpressionFactory<T>::ExpressionFactory() :
		memory() {

}
template<class T>
core::ExpressionFactory<T>::~ExpressionFactory() {

	delete this->memory;

}

template<class T>
core::Expression<T>* ExpressionFactory<T>::Hold(
		core::Expression<T>* exp) const {

	this->memory->insert(exp);
	return exp;

}

template<class T>
core::Expression<T>* ExpressionFactory<T>::newUnary(
		core::UnaryExpression<T>* uExp, core::Expression<T>* exp) {
	return (UnaryExpressionModel<T>*) this->Hold(
			new UnaryExpressionModel<T>(uExp, exp));
}

template<class T>
core::Expression<T>* ExpressionFactory<T>::newBinary(
		core::BinaryExpression<T>* bExp, core::Expression<T>* exp1,
		core::Expression<T>* exp2) {
	return (BinaryExpressionModel<T>*) this->Hold(
			new BinaryExpressionModel<T>(bExp, exp1, exp2));
}

}
#endif /* CORE_EXPRESSIONFACTORY_H_ */
