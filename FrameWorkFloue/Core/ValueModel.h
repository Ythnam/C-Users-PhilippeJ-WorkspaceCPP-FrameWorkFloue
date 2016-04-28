/*
 * ValueModel.h
 *
 *  Created on: 9 févr. 2016
 *      Author: Mathieu
 */
#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"


namespace core
{

template <class T>
class ValueModel : public Expression<T>
{
public :
	ValueModel();
	ValueModel(const T&);
	virtual ~ValueModel(){};
	T evaluate() const;
	void setValue(const T&);

private:
	T value;
};


template <class T>
ValueModel<T>::ValueModel():
value(T(0))
{
}

template <class T>
ValueModel<T>::ValueModel(const T& _value):
value(_value)
{
}

template <class T>
T ValueModel<T>::evaluate() const
{
	return value;
}

template <class T>
void ValueModel<T>::setValue(const T& _value)
{
	value=_value;
}
}
#endif
