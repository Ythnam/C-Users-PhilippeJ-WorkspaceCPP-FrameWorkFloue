/*
 * Evaluator.h
 *
 *  Created on: 3 mars 2016
 *      Author: PhilippeJ
 */

#ifndef FUZZY_EVALUATOR_H_
#define FUZZY_EVALUATOR_H_

#include <vector>

using namespace std;
template <class T>
class Evaluator
{
public : class EvalFunc {

	public : virtual T operator () (const T&)=0;

};

typedef pair<vector<T>,vector<T> > Shape;
static Shape buildShape(const T& min, const T& max, const T& step, EvalFunc& valueOf);

};

template <class T>
typename Evaluator<T>::Shape Evaluator<T>::buildShape(const T& min, const T& max, const T& step, EvalFunc& f) {
	vector<T> x, y;
	for (T i= min ;i <= max ;i += step){
		y.push_back(f(i));
		x.push_back(i);
	}
	return Shape(x,y);
}



#endif /* FUZZY_EVALUATOR_H_ */
