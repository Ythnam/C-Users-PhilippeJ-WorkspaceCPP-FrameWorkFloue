//============================================================================
// Name        : metameta.cpp
// Author      : Mathieu GALLIERE
// Version     :
// Copyright   : all right reserved
//============================================================================

#include <iostream>
#include "ValueModel.h"

using namespace std;
using namespace core;

int main() {
	ValueModel<double> val(0);
	val.setValue(30);
	cout<<val.evaluate()<<endl;
	return 0;
}
