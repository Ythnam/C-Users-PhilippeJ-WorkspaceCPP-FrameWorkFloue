/*
 * AggMax.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef AGGMAX_H_
#define AGGMAX_H_
#include "Agg.h"

namespace fuzzy{

template <class T>
class AggMax : public fuzzy::Agg<T>{

public :
	AggMax();
	virtual ~AggMax(){};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
template <class T>
AggMax<T>::AggMax()
{
}
template <class T>
T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	T l = left->evaluate();
	T r = right->evaluate();
	return (l >= r) ? l : r;
}
}
#endif /* AGGMAX_H_ */
