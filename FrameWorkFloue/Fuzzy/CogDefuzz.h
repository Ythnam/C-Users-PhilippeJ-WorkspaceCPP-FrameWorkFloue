/*
 * CogDefuzz.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_
#include "../Core/BinaryExpression.h"
#include "MamdaniDefuzz.h"


namespace fuzzy{
template <class T>
class CogDefuzz : public fuzzy::MamdaniDefuzz{

public :
	CogDefuzz();
	virtual ~CogDefuzz(){};
	virtual T defuzz(const T&, const T&, const T&, core::Expression<T>* ) const;
private :
	double min,max,step;
};
template <class T>
CogDefuzz<T>::CogDefuzz():
min(0),max(0),step(0)
{
}
template <class T>
T CogDefuzz<T>::defuzz(const T& min, const T& max, const T& step, core::Expression<T>* fuzzySystem) const{
 // A faire cog = sum((value)*coeff)/ sum(coeff*entity)
}

}

#endif /* COGDEFUZZ_H_ */
