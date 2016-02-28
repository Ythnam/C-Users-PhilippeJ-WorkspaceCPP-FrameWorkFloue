/*
 * SugenoDeffuz.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENODEFFUZ_H_
#define FUZZY_SUGENODEFFUZ_H_
#include "NaryExpression.h"

namespace fuzzy{
template <class T>
class SugenoDeffuz : public core::NaryExpression<T>{

public : T evaluate(core::Expression<T>**) const;

};
}




#endif /* FUZZY_SUGENODEFFUZ_H_ */
