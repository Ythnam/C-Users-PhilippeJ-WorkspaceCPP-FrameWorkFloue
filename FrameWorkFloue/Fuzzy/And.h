/*
 * And.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef AND_H_
#define AND_H_
#include "../Core/BinaryExpression.h"

namespace fuzzy {
template<class T>
class And: public core::BinaryExpression<T> {
public:
	And(){};
	virtual ~And() {};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
};
}
#endif /* AND_H_ */
