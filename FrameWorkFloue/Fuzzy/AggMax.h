/*
 * AggMax.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef AGGMAX_H_
#define AGGMAX_H_
#include "Agg.h"

namespace fuzzy{

template <class T>
class AggMax : public fuzzy::Agg<T>{

public : virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};

}
#endif /* AGGMAX_H_ */
