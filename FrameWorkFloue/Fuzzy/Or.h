/*
 * Or.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef OR_H_
#define OR_H_
#include "../Core/BinaryExpression.h"

namespace fuzzy{
template<class T>
class Or:public core::BinaryExpression<T>
{
	public :
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
};
}
#endif /* OR_H_ */
