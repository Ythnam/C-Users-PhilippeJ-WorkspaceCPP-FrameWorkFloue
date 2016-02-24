/*
 * isTriangle.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef ISTRIANGLE_H_
#define ISTRIANGLE_H_
#include "is.h"

namespace fuzzy{
template <class T>
class isTriangle : public fuzzy::is<T>{

private : T min, mid, max;

public : isTriangle(const T&, const T&, const T&);
		 virtual T evaluate(core::Expression<T>*) const;
};

template<class T>
T isTriangle<T>::isTriangle(const T& _min, const T& _mid, const T& _max):min(_min),mid(_mid),max(_max){

}
}
#endif /* ISTRIANGLE_H_ */
