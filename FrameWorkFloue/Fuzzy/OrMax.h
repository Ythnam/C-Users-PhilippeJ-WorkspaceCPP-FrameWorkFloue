/*
 * OrMax.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ORMAX_H_
#define ORMAX_H_
#include "Or.h"

namespace fuzzy{
template <class T>
class OrMax: public fuzzy::Or{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
}
#endif /* ORMAX_H_ */
