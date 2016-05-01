/*
 * SugenoDeffuz.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_
#include "../Core/NaryExpression.h"

namespace fuzzy{
template <class T>
class SugenoDefuzz : public core::NaryExpression<T>{

public :
	virtual ~SugenoDefuzz(){};
	SugenoDefuzz();
	T evaluate(std::vector<core::Expression<T>*>*) const;

};

template<class T>
fuzzy::SugenoDefuzz<T>::SugenoDefuzz(){

}

template<class T>
T fuzzy::SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*>* tabExp) const{

	T numerator =0;
	T denominator = 0;

	for(core::Expression<T>* exp : tabExp){
		numerator = numerator + exp->evaluate();
	}

	for(core::Expression<T>* exp : tabExp){

		/* Ici on a besoin de SugenoThen pour avoir accès a chaque coefficient mis en mémoire dans SugenoThen
		 * C'est pour cela qu'on instancie un BinaryExpressionModel (car SugenoThen est une BinaryExpression).
		 * De plus, on récupère target le target de l'opérateur actuel actuel.
		 * Le target actuel étant un SugenoThen, on peut ainsi récupérer la variable de mémoire tampon prémiseValue */

		core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*) exp;
		core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->GetOperator();
		fuzzy::SugenoThen<T>* sugenoThen = (fuzzy::SugenoThen<T>*) bse->getTarget();

		denominator = denominator + sugenoThen->getPremiseValue();
	}
	if(denominator == 0){
		return null;
	} else{
		return (numerator/denominator);
	}
}

}




#endif /* FUZZY_SUGENODEFUZZ_H_ */
