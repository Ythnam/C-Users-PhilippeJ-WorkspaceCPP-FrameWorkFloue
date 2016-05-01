/*
 * SugenoThen.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */
#ifndef FUZZY_SUGENOTHEN_H_
#define FUZZY_SUGENOTHEN_H_

#include "Then.h"
#include "../Core/NaryExpression.h"

namespace fuzzy{
template <class T>
class SugenoThen : public fuzzy::Then<T>{

	public :
	SugenoThen();
	virtual ~SugenoThen(){};
	SugenoThen(T);
	T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	T getPremiseValue() const;
	void setPremiseValue(T);

	private :
	T premiseValue;
};

template<class T>
fuzzy::SugenoThen<T>::SugenoThen():premiseValue(0){

}

template<class T>
fuzzy::SugenoThen<T>::SugenoThen(T _premiseValue):premiseValue(_premiseValue){

}

template<class T>
T fuzzy::SugenoThen<T>::evaluate(core::Expression<T>* coeff, core::Expression<T>* exp) const{

	this->premiseValue = coeff->evaluate();
	T res =this->premiseValue*exp->evaluate();
			return res;
}

template <class T>
T fuzzy::SugenoThen<T>::getPremiseValue() const{
	return premiseValue;
}

template <class T>
void fuzzy::SugenoThen<T>::setPremiseValue(T _setPremiseValue){
	this->premiseValue = _setPremiseValue;
}
}


#endif
