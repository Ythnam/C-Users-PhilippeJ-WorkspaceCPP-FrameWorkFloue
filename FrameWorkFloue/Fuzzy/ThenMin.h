/*
 * ThenMin.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef THENMIN_H_
#define THENMIN_H_
#include "Then.h"

namespace fuzzy{
template <class T>
class ThenMin : public fuzzy::Then<T>{

public :
	ThenMin();
	virtual	~ThenMin(){};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
template <class T>
ThenMin<T>::ThenMin()
{
}
template <class T>
T ThenMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
	T l = left->evaluate();
	T r = right->evaluate();
	return (l <= r) ? l : r;
}
}
#endif /* THENMIN_H_ */
