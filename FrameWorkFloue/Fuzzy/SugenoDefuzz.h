/*
 * SugenoDeffuz.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_
#include "NaryExpression.h"

namespace fuzzy{
template <class T>
class SugenoDeffuz : public core::NaryExpression<T>{

public :
	virtual ~SugenoDefuzz(){};
	T evaluate(vector<core::Expression<T>*>) const;

};

}




#endif /* FUZZY_SUGENODEFUZZ_H_ */
