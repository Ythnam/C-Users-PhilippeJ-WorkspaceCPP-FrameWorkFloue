/*
 * ThenMult.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef THENMULT_H_
#define THENMULT_H_
#include "Then.h"

namespace fuzzy{
template <class T>
class ThenMult : public fuzzy::Then{

public : T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
}
#endif /* THENMULT_H_ */
