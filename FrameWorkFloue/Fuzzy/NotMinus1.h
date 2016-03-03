/*
 * NotMinus1.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef NOTMINUS1_H_
#define NOTMINUS1_H_
#include "Not.h"

namespace fuzzy{
template <class T>
	class NotMinus1 : public Not<T>
	{
	public :
		T evaluate(core::Expression<T>*) const;
	};

	template<class T>
	T NotMinus1<T>::evaluate(core::Expression<T>* e) const
	{
		T ev=e->evaluate();
		return 1-ev;
	}
}
#endif /* NOTMINUS1_H_ */
