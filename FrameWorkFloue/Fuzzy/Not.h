/*
 * Not.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef NOT_H_
#define NOT_H_
#include "../Core/UnaryExpression.h"

namespace fuzzy{
template <class T>
class Not : public core::UnaryExpression<T>{
public:
	virtual ~Not(){};
		virtual T evaluate(core::Expression<T>*) const=0;
};
}
#endif /* NOT_H_ */
