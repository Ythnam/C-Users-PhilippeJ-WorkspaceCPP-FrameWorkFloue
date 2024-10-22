/*
 * Agg.h
 *
 *  Created on: 2 f�vr. 2016
 *      Author: PhilippeJ
 */

#ifndef AGG_H_
#define AGG_H_
#include "../Core/BinaryExpression.h"

namespace fuzzy {
template<class T>
class Agg: public core::BinaryExpression<T> {
public:
	virtual ~Agg() {};
	virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const = 0;
};
}
#endif /* AGG_H_ */
