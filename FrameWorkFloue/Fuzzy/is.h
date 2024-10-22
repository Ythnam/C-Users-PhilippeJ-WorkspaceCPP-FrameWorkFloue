/*
 * is.h
 *
 *  Created on: 2 f�vr. 2016
 *      Author: PhilippeJ
 */

#ifndef IS_H_
#define IS_H_
#include "../Core/UnaryExpression.h"

namespace fuzzy {
template<class T>
class is: public core::UnaryExpression<T> {
public:
	virtual ~is() {};
	virtual T evaluate(core::Expression<T>*) const=0;
};
}
#endif /* IS_H_ */
