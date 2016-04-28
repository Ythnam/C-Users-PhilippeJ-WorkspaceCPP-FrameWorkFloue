/*
 * Then.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef THEN_H_
#define THEN_H_
#include "../Core/BinaryExpression.h"

namespace fuzzy{
template<class T>
class Then : public core::BinaryExpression<T>
{
	public :
	virtual ~Then(){};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
};
}
#endif /* THEN_H_ */
