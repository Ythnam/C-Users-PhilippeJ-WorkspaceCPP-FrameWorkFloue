/*
 * SugenoDeffuz.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_
#include "NaryExpression.h"

namespace fuzzy{
template <class T>
class SugenoDefuzz : public core::NaryExpression<T>{

public :
	virtual ~SugenoDefuzz(){};
	SugenoDefuzz();
	T evaluate(std::vector<core::Expression<T>*>) const;

};

template<class T>
fuzzy::SugenoDefuzz<T>::SugenoDefuzz(){

}

template<class T>
T fuzzy::SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*> tabExp) const{

}

}




#endif /* FUZZY_SUGENODEFUZZ_H_ */
