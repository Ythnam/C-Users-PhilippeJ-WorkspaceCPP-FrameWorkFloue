/*
 * SugenoConclusion.h
 *
 *  Created on: 28 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_SUGENOCONCLUSION_H_
#define FUZZY_SUGENOCONCLUSION_H_
#include "../Core/NaryExpression.h"
//Zi c'est lacombinaison lineaire des entrés
//wi c'est l'evaluation de la partie antécédante:
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

private : std::vector<T> coeff;

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
	if(this->coeff.size() == tabExp->size()){
		int i = 0;
		std::vector<T> save; // on sauvegarde les wi*zi dedans

		for(core::Expression<T>* exp : tabExp){
			//T sauveEvaluate = exp.core::evaluate();
			save.add(this->coeff.get[i]*(exp)->evaluate()); //
			i++; // permet d'itérer sur les coeffs
		}

		T cumulExp = 0;
		for(T expSave : save){
			cumulExp = cumulExp + expSave;
		}

		return cumulExp;

	} else{
		std::cout << "error : coeff's size vector is different of expression's size vector " << endl;
		return null;
	}

}
}
#endif /* FUZZY_SUGENOCONCLUSION_H_ */

/*
 */
