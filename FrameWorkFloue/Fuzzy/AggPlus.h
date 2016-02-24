/*
 * AggPlus.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef AGGPLUS_H_
#define AGGPLUS_H_
#include "Agg.h"

namespace fuzzy{
template <class T>
class AggPlus : public fuzzy::Agg<T>{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

}
#endif /* AGGPLUS_H_ */
