/*
 * OrPlus.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ORPLUS_H_
#define ORPLUS_H_
#include "Or.h"

namespace fuzzy{
template <class T>
class OrPlus : public fuzzy::Or{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
}
#endif /* ORPLUS_H_ */
