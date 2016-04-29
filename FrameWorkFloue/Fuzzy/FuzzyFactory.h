/*
 * FuzzyFactory.h
 *
 *  Created on: 29 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_FUZZYFACTORY_H_
#define FUZZY_FUZZYFACTORY_H_
#include "../Core/Expression.h"
#include "../Core/BinaryExpression.h"
#include "../Core/UnaryExpression.h"
#include "../Core/BinaryShadowExpression.h"
#include "../Core/UnaryShadowExpression.h"
#include "../Core/ExpressionFactory.h"
#include "Agg.h"
#include "And.h"
#include "Or.h"
#include "Then.h"
#include "CogDefuzz.h"
#include "Not.h"
#include "Is.h"

namespace fuzzy {
template<class T>
class FuzzyFactory: public core::ExpressionFactory<T> {

public:
	FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, CogDefuzz<T>*);
	virtual ~FuzzyFactory() {
	}
	;
	core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>*);
	core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
	core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
	core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
	core::Expression<T>* newDefuzz(core::Expression<T>*, core::Expression<T>*);
	core::Expression<T>* newNot(core::Expression<T>*);
	core::Expression<T>* NewIs(core::Expression<T>* o, fuzzy::is<T>* is);

	void changeNot(fuzzy::Not<T>*);
	void changeAnd(fuzzy::And<T>*);
	void changeOr(fuzzy::Or<T>*);
	void changeThen(fuzzy::Then<T>*);
	void changeAgg(fuzzy::Agg<T>*);
	void changeDefuzz(fuzzy::CogDefuzz<T>*);

private:
	core::UnaryShadowExpression<T>* notUE;
	core::BinaryShadowExpression<T>* andBE;
	core::BinaryShadowExpression<T>*orBE;
	core::BinaryShadowExpression<T>*thenBE;
	core::BinaryShadowExpression<T>*aggBE;
	core::BinaryShadowExpression<T>* defuzzBE;

	/*core::BinaryExpressionModel<T>* andBE, orBE, thenBE, aggBE, defuzzBE;
	 core::UnaryExpressionModel<T>* notUE;*/
};

template<class T>
FuzzyFactory<T>::FuzzyFactory(fuzzy::Not<T>* _notUE, fuzzy::And<T>* _andBE,
		fuzzy::Or<T>* _orBE, fuzzy::Then<T>* _thenBE, fuzzy::Agg<T>* _aggBE,
		fuzzy::CogDefuzz<T>* _defuzzBE) {
	changeNot(_notUE);
	changeAnd(_andBE);
	changeOr(_orBE);
	changeThen(_thenBE);
	changeAgg(_aggBE);
	changeDefuzz(_defuzzBE);
}

template<class T>
core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* left,
		core::Expression<T>* right) {

	return this->newBinary(andBE, left, right);

}

template<class T>
core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* left,
		core::Expression<T>* right) {

	return this->newBinary(orBE, left, right);

}

template<class T>
core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* left,
		core::Expression<T>* right) {

	return this->newBinary(thenBE, left, right);

}

template<class T>
core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* left,
		core::Expression<T>* right) {

	return this->newBinary(aggBE, left, right);

}

template<class T>
core::Expression<T>* FuzzyFactory<T>::newDefuzz(core::Expression<T>* left,
		core::Expression<T>* right) {

	return this->newBinary(defuzzBE, left, right);

}

template<class T>
core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o) {

	return this->newUnary(notUE, o);

}

template<class T>
core::Expression<T>* FuzzyFactory<T>::NewIs(core::Expression<T>* o,
		fuzzy::is<T>* is) {
	return this->newUnary(is, o);
}
template<class T>
void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* _and) {
	andBE->setTarget(_and);
}

template<class T>
void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* _or) {
	orBE->setTarget(_or);
}

template<class T>
void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* _then) {
	thenBE->setTarget(_then);
}

template<class T>
void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* _agg) {
	aggBE->setTarget(_agg);
}
template<class T>
void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* _not) {
	notUE->setTarget(_not);
}
template<class T>
void FuzzyFactory<T>::changeDefuzz(fuzzy::CogDefuzz<T>* _defuzz) {
	defuzzBE->setTarget(_defuzz);
}

}

#endif /* CORE_FUZZYFACTORY_H_ */
