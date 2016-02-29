/*
 * FuzzyFactory.h
 *
 *  Created on: 29 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef CORE_FUZZYFACTORY_H_
#define CORE_FUZZYFACTORY_H_
#include "Expression.h"

namespace core{
template <class T>
class FuzzyFactory : public ExpressionFactory{

public : core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newNot(core::Expression<T>*);
		 core::Expression<T>* newIs(fuzzy::is, core::Expression<T>*);

		 void changeAnd(fuzzy::And);
		 void changeOr(fuzzy::Or);
		 void changeThen(fuzzy::Then);

private : BinaryShadowExpression<T>* andBE, orBE, thenBE, aggBE, defuzzBE;
		  UnaryShadowExpression<T>* notUE;

};

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newAnd(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(andBE, left, right);

}

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newOr(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(orBE, left, right);

}

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newThen(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(thenBE, left, right);

}

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newAgg(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(aggBE, left, right);

}

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newDefuzz(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(defuzzBE, left, right);

}

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newNot(core::Expression<T>* o){

	return newUnary(notUE, o);

}

template <class T>
core::Expression<T>* core::FuzzyFactory<T>::newIs(fuzzy::is isSomething, core::Expression<T>* o){

	return newUnary(isSomething, o);

}

}
#endif /* CORE_FUZZYFACTORY_H_ */
