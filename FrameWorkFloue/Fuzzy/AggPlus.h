/*
 * AggPlus.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef AGGPLUS_H_
#define AGGPLUS_H_
#include "Agg.h"

namespace fuzzy{
template <class T>
class AggPlus : public fuzzy::Agg<T>{

public :
	AggPlus();
	virtual ~AggPlus(){};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
template <class T>
AggPlus<T>::AggPlus()
	{
	}
template <class T>
T AggPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	return left->evaluate() + right->evaluate();
}
}
#endif /* AGGPLUS_H_ */
