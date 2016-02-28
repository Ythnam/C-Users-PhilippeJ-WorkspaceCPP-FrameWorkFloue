/*
 * SugenoThen.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENOTHEN_H_
#define FUZZY_SUGENOTHEN_H_
#include "Then.h"

namespace fuzzy{
template <class T>
class SugenoThen : public fuzzy::Then{

public : T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		 T premiseValue();

private : T premiseValue;
};



}




#endif /* FUZZY_SUGENOTHEN_H_ */
