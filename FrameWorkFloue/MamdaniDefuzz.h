/*
 * MamdaniDefuzz.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef MAMDANIDEFUZZ_H_
#define MAMDANIDEFUZZ_H_
#include "BinaryExpression.h"

namespace fuzzy{
template <class T>
class MamdaniDefuzz : public core::BinaryExpression{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
}
#endif /* MAMDANIDEFUZZ_H_ */
