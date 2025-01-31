/*
 * SugenoConclusion.h
 *
 *  Created on: 28 f�vr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENOCONCLUSION_H_
#define FUZZY_SUGENOCONCLUSION_H_
#include "../Core/NaryExpression.h"
#include <iostream>
#include <vector>
//Zi c'est lacombinaison lineaire des entr�s
//wi c'est l'evaluation de la partie ant�c�dante:
//->
namespace fuzzy{
template <class T>
class SugenoConclusion : public core::NaryExpression<T>{

public :
	virtual ~SugenoConclusion(){};
	SugenoConclusion(std::vector<T>*);
	SugenoConclusion();
	std::vector<T*> getCoeff();
	void setCoeff(std::vector<T>*);
	T evaluate(std::vector<core::Expression<T>*>*) const;

private : std::vector<T>* coeff;

};

template< class T>
fuzzy::SugenoConclusion<T>::SugenoConclusion():coeff(){

}

template<class T>
fuzzy::SugenoConclusion<T>::SugenoConclusion(std::vector<T>* _coeff):coeff(_coeff){

}

template<class T>
std::vector<T*> fuzzy::SugenoConclusion<T>::getCoeff(){
	return this->coeff();
}

template<class T>
void fuzzy::SugenoConclusion<T>::setCoeff(std::vector<T>* _coeff){
	this->coeff = _coeff;
}

template<class T>
T fuzzy::SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*>* tabExp) const {
	if(this->coeff->size() == tabExp->size()){
		//int i = 0;
		std::vector<T> save; // on sauvegarde les wi*zi dedans

		//for(core::Expression<T>* exp : tabExp){
		for(unsigned int j =0; j < tabExp->size(); j++){
			//T sauveEvaluate = exp.core::evaluate();
			save.push_back( (this->coeff->at(j)) * ((tabExp->at(j))->evaluate())); //
			//i++; // permet d'it�rer sur les coeffs
		}

		T cumulExp = 0;
		//for(T expSave : save){
		for(unsigned int k = 0; k < tabExp->size(); k++){
			cumulExp = cumulExp + save.at(k);
		}

		return cumulExp;

	} else{
		std::cout << "error : coeff's size vector is different of expression's size vector " << endl;
	}

}
}
#endif /* FUZZY_SUGENOCONCLUSION_H_ */

/*
 */
