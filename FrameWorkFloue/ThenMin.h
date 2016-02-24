/*
 * ThenMin.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef THENMIN_H_
#define THENMIN_H_

namespace fuzzy{
template <class T>
class ThenMin : public fuzzy::Then{

public : T evaluate(core::Expression<T>*, core::Expression<T>*) const;

};
}
#endif /* THENMIN_H_ */
