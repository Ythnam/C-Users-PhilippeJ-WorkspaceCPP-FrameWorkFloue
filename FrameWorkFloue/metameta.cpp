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
#include "Fuzzy/NotMinus1.h"
#include "Fuzzy/OrMax.h"
#include "Fuzzy/ThenMin.h"


// Extension logique numerique
//
//
using namespace std;
using namespace core;

int main() {
	ValueModel<double> val(0.8);
	ValueModel<double>* val_ptr;
	val_ptr=&val;
	val_ptr->setValue(0.7);
	cout<<val_ptr->evaluate()<< " step 1"<< endl;

	ValueModel<double> val2(0.9);
	ValueModel<double>* val_ptr2=0;
	val_ptr2=&val2;
	val_ptr2->setValue(0.5);
	//cout<<val_ptr2->evaluate()<< endl;


	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	UnaryExpressionModel<double>* unary_ptr=0;
	UnaryExpressionModel<double> uem(&opNot,val_ptr);
	unary_ptr=&uem;
	cout<<unary_ptr->GetOperand()->evaluate()<<endl;
	cout<<unary_ptr->GetOperator()->evaluate(val_ptr)<<endl;


	BinaryExpressionModel<double>* binary_ptr;
	BinaryExpressionModel<double> bem(&opAnd,val_ptr,val_ptr2);
	binary_ptr=&bem;
	cout<<binary_ptr->GetLeft()->evaluate()<<" et "<< binary_ptr->GetRight()->evaluate()<<endl;
	cout<<binary_ptr->GetOperator()->evaluate(val_ptr,val_ptr2)<<endl;


	binary_ptr->SetOperator(&opThen);
		cout<<binary_ptr->GetOperator()->evaluate(val_ptr,val_ptr2)<<endl;

	binary_ptr->SetOperator(&opOr);
		cout<<binary_ptr->GetOperator()->evaluate(val_ptr,val_ptr2)<<endl;

		return 0;
}
