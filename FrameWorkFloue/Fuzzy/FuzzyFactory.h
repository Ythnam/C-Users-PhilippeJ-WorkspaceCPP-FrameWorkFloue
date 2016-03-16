/*
 * FuzzyFactory.h
 *
 *  Created on: 29 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_FUZZYFACTORY_H_
#define FUZZY_FUZZYFACTORY_H_
#include "../Core/Expression.h"

namespace fuzzy{
template <class T>
class FuzzyFactory : public core::ExpressionFactory{

public : core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);
		 core::Expression<T>* newNot(core::Expression<T>*);
		 core::Expression<T>* newIs(fuzzy::is, core::Expression<T>*);

		 void changeAnd(fuzzy::And<T>*);
		 void changeOr(fuzzy::Or<T>*);
		 void changeThen(fuzzy::Then<T>*);
		 void changeAgg(fuzzy::Agg<T>*);

private :
		 /*
		  core::BinaryShadowExpression<T>* andBE, orBE, thenBE, aggBE, defuzzBE;
		  core::UnaryShadowExpression<T>* notUE;
		*/
		 core::BinaryExpression<T>* andBE, orBE, thenBE, aggBE, defuzzBE;
		 core::UnaryExpression<T>* notUE;
};

template <class T>
core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(andBE, left, right);

}

template <class T>
core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(orBE, left, right);

}

template <class T>
core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(thenBE, left, right);

}

template <class T>
core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(aggBE, left, right);

}

template <class T>
core::Expression<T>* FuzzyFactory<T>::newDefuzz(core::Expression<T>* left, core::Expression<T>* right){

	return newBinary(defuzzBE, left, right);

}

template <class T>
core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o){

	return newUnary(notUE, o);

}

template <class T>
core::Expression<T>* FuzzyFactory<T>::newIs(fuzzy::is isSomething, core::Expression<T>* o){

	return newUnary(isSomething, o);

}

template <class T>
void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* _and){
	andBE->setTarget(_and);
}

template <class T>
void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* _or){
	orBE->setTarget(_or);
}

template <class T>
void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* _then){
	thenBE->setTarget(_then);
}

template <class T>
void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* _agg){
	aggBE->setTarget(_agg);
}
}
#endif /* CORE_FUZZYFACTORY_H_ */
