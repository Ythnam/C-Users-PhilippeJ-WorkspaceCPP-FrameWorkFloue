/*
 * SugenoConclusion.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENOCONCLUSION_H_
#define FUZZY_SUGENOCONCLUSION_H_
#include "NaryExpression.h"
#include "iterator.h"
//Zi c'est lacombinaison lineaire des entrés
//wi c'est l'evaluation de la partie antécédante:
//->
namespace fuzzy{
template <class T>
class SugenoConclusion : public core::NaryExpression<T>{

public :
	virtual ~SugenoConclusion(){}
	virtual T evaluate(std::vector<core::Expression<T>*>) const;

private : vector<core::Expression<T>*> coeff;

};

template<class T>
T evaluate(std::vector<core::Expression<T>*> tabExp){
	tabExp::iterator it = tabExp.begin();
}
}
#endif /* FUZZY_SUGENOCONCLUSION_H_ */

/*
 */
