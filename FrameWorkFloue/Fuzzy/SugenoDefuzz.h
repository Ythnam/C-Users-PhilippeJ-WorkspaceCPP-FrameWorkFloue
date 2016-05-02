/*
 * SugenoDeffuz.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_
#include "../Core/NaryExpression.h"
#include "../Fuzzy/SugenoThen.h"
#include <vector>
#include <iterator>
#include "../Core/Expression.h"

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
T fuzzy::SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*>* tabExp) const{

	T numerator =0;
	T denominator = 0;

	//for(core::Expression<T>* exp : tabExp){
	for(unsigned int i = 0; i < tabExp->size(); i++){
		numerator = numerator + tabExp->at(i)->evaluate();
		//std::cout << "Iteration " << i << " : " << numerator << std::endl;
	}


	typename std::vector<core::Expression<T>*>::iterator it ;
	//for(core::Expression<T>* exp : tabExp){
	//for(unsigned int j =0; j < tabExp->size(); j++){
	for(it = tabExp->begin(); it != tabExp->end(); it++){

		/* Ici on a besoin de SugenoThen pour avoir accès a chaque coefficient mis en mémoire dans SugenoThen
		 * C'est pour cela qu'on instancie un BinaryExpressionModel (car SugenoThen est une BinaryExpression).
		 * De plus, on récupère target le target de l'opérateur actuel actuel.
		 * Le target actuel étant un SugenoThen, on peut ainsi récupérer la variable de mémoire tampon prémiseValue */

		//core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*) tabExp->at(j);

		core::BinaryExpressionModel<T> *bem = (core::BinaryExpressionModel<T>*) (*it);
		core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->GetOperator();
		fuzzy::SugenoThen<T>* sugenoThen = (fuzzy::SugenoThen<T>*) bse->getTarget();
		std::cout << "ok" << std::endl;

		denominator = denominator + sugenoThen->getPremiseValue();
		//std::cout << j << " " << denominator <<  std::endl;
	}
	if(denominator == 0){
		return NULL;
	} else{
		return (numerator/denominator);
	}
}

}




#endif /* FUZZY_SUGENODEFUZZ_H_ */
