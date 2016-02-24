/*
 * ValueModel.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef VALUEMODEL_H_
#define VALUEMODEL_H_
#include "Expression.h"

namespace core{
template <class T>
class ValueModel : public Expression<T>{

public : ValueModel();
		 ValueModel(const T&);
		 virtual ~ValueModel(){};

		 virtual T evaluate() const;
		 virtual void setValue(const T&);

private : T value;

};

template <class T>
ValueModel<T>::valueModel():value(0){

}

template <class T>
ValueModel<T>::valueModel(const T& _value):value(_value){

}

template <class T>
void ValueModel<T>::setValue(const T& _value){
	value=_value;
}

template <class T>
T ValueModel<T>::evaluate() const{
	return value;
}

}
#endif /* VALUEMODEL_H_ */
