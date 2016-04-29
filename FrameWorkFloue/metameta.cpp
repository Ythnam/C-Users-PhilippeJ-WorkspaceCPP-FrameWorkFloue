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
#include "Fuzzy/AggMax.h"
#include "Fuzzy/ThenMin.h"
#include "Fuzzy/CogDefuzz.h"
#include "Fuzzy/isTriangle.h"
#include "Fuzzy/FuzzyFactory.h"

// Extension logique numerique
//
//
using namespace std;
using namespace core;

int main() {
	/*
	 ValueModel<double> val(0.8);
	 ValueModel<double>* val_ptr;
	 val_ptr = &val;
	 val_ptr->setValue(0.7);
	 cout << val_ptr->evaluate() << " step 1" << endl;

	 ValueModel<double> val2(0.9);
	 ValueModel<double>* val_ptr2 = 0;
	 val_ptr2 = &val2;
	 val_ptr2->setValue(0.5);
	 //cout<<val_ptr2->evaluate()<< endl;

	 fuzzy::OrMax<double> opOr;
	 fuzzy::ThenMin<double> opThen;
	 fuzzy::NotMinus1<double> opNot;
	 fuzzy::AndMin<double> opAnd;
	 fuzzy::CogDefuzz<double> opDefuzz(0.0,10.0,1.0);
	 UnaryExpressionModel<double>* unary_ptr = 0;
	 UnaryExpressionModel<double> uem(&opNot, val_ptr);
	 unary_ptr = &uem;
	 cout << unary_ptr->GetOperand()->evaluate() << endl;
	 cout << unary_ptr->GetOperator()->evaluate(val_ptr) << endl;

	 BinaryExpressionModel<double>* binary_ptr;
	 BinaryExpressionModel<double> bem(&opAnd, val_ptr, val_ptr2);
	 binary_ptr = &bem;
	 cout << binary_ptr->GetLeft()->evaluate() << " et "
	 << binary_ptr->GetRight()->evaluate() << endl;
	 cout << binary_ptr->GetOperator()->evaluate(val_ptr, val_ptr2) << endl;

	 binary_ptr->SetOperator(&opDefuzz);
	 cout << binary_ptr->GetOperator()->evaluate(val_ptr, val_ptr2) << endl;
	 */
	//final test
	//operators
	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::AggMax<double> opAgg;
	fuzzy::CogDefuzz<double> opDefuzz;

	//fuzzy expression factory
	fuzzy::FuzzyFactory<double> f(opNot, opAnd, opOr, opThen, opAgg, opDefuzz);
	//membership function
	fuzzy::isTriangle<double> poor(-5, 0, 5);
	fuzzy::isTriangle<double> good(0, 5, 10);
	fuzzy::isTriangle<double> excellent(5, 10, 15);
	fuzzy::isTriangle<double> cheap(0, 5, 10);
	fuzzy::isTriangle<double> average(10, 15, 20);
	fuzzy::isTriangle<double> generous(20, 25, 30);
	//unary_ptr->SetOperator(&poor);
	//cout <<"test unary" << unary_ptr->GetOperator()->evaluate(val_ptr) << endl;
	/*
	 //values
	 Value
	 service(,0);
	 Value food(0);
	 Value tips(0);
	 */
	//Expression *r = f.NewAgg(	f.NewAgg(f.NewThen(f.NewIs(&service, &poor), f.NewIs(&tips, &cheap)),f.NewThen(f.NewIs(&service, &good),f.NewIs(&tips, &average))),f.NewThen(f.NewIs(&service, &excellent),f.NewIs(&tips, &generous)));
	//defuzzification
	/*
	 Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);
	 //apply input
	 float s;
	 while (true) {
	 cout << "service : ";
	 cin >> s;
	 service.SetValue(s);
	 cout << "tips -> " << system->Evaluate() << endl;
	 }
	 */
	return 0;
}
