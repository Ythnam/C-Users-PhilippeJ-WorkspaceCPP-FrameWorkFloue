//============================================================================
// Name        : metameta.cpp
// Author      : Mathieu GALLIERE
// Version     :
// Copyright   : all right reserved
//============================================================================

#include <iostream>
#include "Core/ValueModel.h"
#include "Core/UnaryExpressionModel.h"
#include "Core/BinaryExpressionModel.h"
#include "Fuzzy/AndMin.h"

using namespace std;
using namespace core;

int main() {
	ValueModel<double> val(0);
	ValueModel<double>* val_ptr;
	val_ptr=&val;
	val_ptr->setValue(50);
	cout<<val_ptr->evaluate()<< endl;


	ValueModel<double> val2(20);
	ValueModel<double>* val_ptr2;
	val_ptr2=&val2;
	val_ptr2->setValue(30);
	cout<<val_ptr2->evaluate()<< endl;

	fuzzy::AndMin<double> opAnd;
	BinaryExpressionModel<double>* binary_ptr=0;
	BinaryExpressionModel<double> bem(&opAnd,val_ptr,val_ptr2);
	binary_ptr=&bem;
	cout<<binary_ptr->GetLeft()->evaluate()<<" et "<< binary_ptr->GetRight()->evaluate()<<endl;
	cout<<binary_ptr->GetOperator()->evaluate(val_ptr,val_ptr2)<<endl;

	return 0;
}
