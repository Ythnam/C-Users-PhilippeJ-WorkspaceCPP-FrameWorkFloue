/*
 * NotMinus1.h
 *
 *  Created on: 2 f�vr. 2016
 *      Author: PhilippeJ
 */

#ifndef NOTMINUS1_H_
#define NOTMINUS1_H_
#include "Not.h"

namespace fuzzy{
template <class T>
class NotMinus1 : public fuzzy::Not{

public : virtual T evaluate(core::Expression<T>*) const;

};

template <class T>
T NotMinus1<T>::evaluate(core::Expression<T>* o)const{
	return 1 - o->evaluate();
}
}
#endif /* NOTMINUS1_H_ */
