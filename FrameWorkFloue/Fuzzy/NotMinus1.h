/*
 * NotMinus1.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef NOTMINUS1_H_
#define NOTMINUS1_H_
#include "Not.h"

namespace fuzzy{
template <class T>
class NotMinus1 : public fuzzy::Not{

public : virtual T evaluate(core::Expression<T>*) const;

};
}
#endif /* NOTMINUS1_H_ */
