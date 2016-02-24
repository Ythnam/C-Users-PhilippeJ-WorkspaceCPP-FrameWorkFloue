/*
 * Expression.h
 *
 *  Created on: 2 févr. 2016
 *      Author: PhilippeJ
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

namespace core{
template <class T>
class Expression{

public : virtual T evaluate() const = 0;

};

}

#endif /* EXPRESSION_H_ */
