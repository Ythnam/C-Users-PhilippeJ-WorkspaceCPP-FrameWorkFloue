/*
 * CogDefuzz.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_
#include "Core/BinaryExpression.h"


namespace fuzzy{
template <class T>
class CogDefuzz : public fuzzy::MamdaniDefuzz{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

template <class T>
T CogDefuzz<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
 // A faire
}
}

#endif /* COGDEFUZZ_H_ */
