//============================================================================
// Name        : metameta.cpp
// Author      : Mathieu GALLIERE
// Version     :
// Copyright   : all right reserved
//============================================================================

#include <iostream>
#include "Core/ValueModel.h"
#include "Core/UnaryExpressionModel.h"
#include "Core/UnaryShadowExpression.h"
#include "Core/BinaryExpressionModel.h"
#include "Core/BinaryShadowExpression.h"
#include "Core/NaryExpressionModel.h"
#include "Core/NaryShadowExpression.h"
#include "Fuzzy/AndMin.h"
#include "Fuzzy/NotMinus1.h"
#include "Fuzzy/OrMax.h"
#include "Fuzzy/AggMax.h"
#include "Fuzzy/ThenMin.h"
#include "Fuzzy/CogDefuzz.h"
#include "Fuzzy/isTriangle.h"
#include "Fuzzy/FuzzyFactory.h"
#include "Fuzzy/SugenoConclusion.h"
#include "Fuzzy/SugenoDefuzz.h"
//#include "Fuzzy/SugenoThen.h"
//#include "Fuzzy/SugenoConclusion.h"
//#include "Fuzzy/SugenoDefuzz.h"

// Projet Réalisé par Mathieu Galliere et Philippe Jacob.
// Certaines lignes de codes sont sembables au projet de Dimitri Reynie et Cedric Szymanski
// Cela est dû au fait qu'ils nous ont aidés à réalisé certaines parties. Ils nous ont expliqué et nous ont aiguillé.

using namespace std;
using namespace core;

int main() {

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

	fuzzy::NotMinus1<double> opNot;
	fuzzy::AndMin<double> opAnd;
	fuzzy::OrMax<double> opOr;
	fuzzy::ThenMin<double> opThen;
	fuzzy::AggMax<double> opAgg;
	fuzzy::CogDefuzz<double> opDefuzz(0, 25, 1);
	UnaryExpressionModel<double>* unary_ptr = 0;
	UnaryExpressionModel<double> uem(&opNot, val_ptr);

	unary_ptr = &uem;
	UnaryShadowExpression<double> usem(unary_ptr);
	cout << usem.getTarget()->evaluate(unary_ptr) << endl;
	cout << unary_ptr->GetOperator()->evaluate(val_ptr) << endl;

	BinaryExpressionModel<double>* binary_ptr;
	BinaryExpressionModel<double> bem(&opAnd, val_ptr, val_ptr2);
	binary_ptr = &bem;
	BinaryShadowExpression<double> bsem(binary_ptr);
	cout << binary_ptr->GetLeft()->evaluate() << " et "
			<< binary_ptr->GetRight()->evaluate() << endl;
	cout << bsem.getTarget()->evaluate(val_ptr, val_ptr2) << endl;

	binary_ptr->SetOperator(&opDefuzz);
	cout << binary_ptr->GetOperator()->evaluate(val_ptr, val_ptr2) << endl;

	//final test
	//operators
	/*
	 fuzzy::NotMinus1<double> opNot;
	 fuzzy::AndMin<double> opAnd;
	 fuzzy::OrMax<double> opOr;
	 fuzzy::ThenMin<double> opThen;
	 fuzzy::AggMax<double> opAgg;
	 fuzzy::CogDefuzz<double> opDefuzz(0, 25, 1);
	 */
	//fuzzy expression factory
	fuzzy::FuzzyFactory<double> f(&opNot, &opAnd, &opOr, &opThen, &opAgg,
			&opDefuzz);
	//membership function
	fuzzy::isTriangle<double> poor(-5, 0, 5);
	fuzzy::isTriangle<double> good(0, 5, 10);
	fuzzy::isTriangle<double> excellent(5, 10, 15);
	fuzzy::isTriangle<double> cheap(0, 5, 10);
	fuzzy::isTriangle<double> average(10, 15, 20);
	fuzzy::isTriangle<double> generous(20, 25, 30);
	//unary_ptr->SetOperator(&poor);
	//cout <<"test unary" << unary_ptr->GetOperator()->evaluate(val_ptr) << endl;

	//values
	ValueModel<double> service(0);
	ValueModel<double> food(0);
	ValueModel<double> tips(0);
	ValueModel<double>* val_ptrs;
	ValueModel<double>* val_ptrf;
	ValueModel<double>* val_ptrt;
	val_ptrs = &service;
	val_ptrf = &food;
	val_ptrt = &tips;
	//fuzzy::SugenoThen<double> sugeno;
	//fuzzy::SugenoConclusion<double> sugenoC;
//	fuzzy::SugenoDefuzz<double> sugenoD;
	//NaryExpressionModel<double>();
	//f.NewIs(&tips, &cheap);
	Expression<double> *r = f.newAgg(
			f.newAgg(
					f.newThen(f.newIs(val_ptrs, &poor),
							f.newIs(val_ptrt, &cheap)),
					f.newThen(f.newIs(val_ptrs, &good),
							f.newIs(val_ptrt, &average))),
			f.newThen(f.newIs(val_ptrs, &excellent),
					f.newIs(val_ptrt, &generous)));
	//defuzzification

	Expression<double>* system = f.newDefuzz(val_ptrt, r, 0, 25, 1);
	//apply input
	float s;
	while (true) {
		cout << "service : ";
		cin >> s;
		val_ptrs->setValue(s);
		cout << "tips -> " << system->evaluate() << endl;
	};

	/*

	 // Test sur SugenoConclusion
	 std::vector<double> _coeff(3);
	 _coeff[0] = 1;
	 _coeff[1] = 2;
	 _coeff[2] = 3;
	 for(int i=0; i<3; i++){
	 std::cout << _coeff[i] <<std::endl;
	 }

	 core::ValueModel<double> test1(1);
	 core::ValueModel<double> test2(2);
	 core::ValueModel<double> test3(5);
	 fuzzy::SugenoConclusion<double> sugConc(&_coeff);
	 std::vector<core::Expression<double>* > tabExp;
	 tabExp.push_back(&test1);
	 tabExp.push_back(&test2);
	 tabExp.push_back(&test3);
	 for(int i=0; i<3; i++){
	 std::cout << tabExp.at(i) <<std::endl;
	 }

	 //sugConc.evaluate(&tabExp);
	 std::cout << "Sugeno Conclusion : " << sugConc.evaluate(&tabExp) << std::endl;


	 //SugenoDefuzz et donc sur SugenoThen

	 fuzzy::SugenoThen<double> sugThen;
	 std::cout << "Sugeno Then : " << sugThen.evaluate(&test3, &test2) << std::endl;
	 std::cout << "Premise Value " << sugThen.getPremiseValue() << std::endl;



	 // fuzzy::SugenoDefuzz<double> sugDef;
	 // std::cout << "Sugeno Defuzz : " << sugDef.evaluate(&tabExp) << std::endl;
	 */
	return 0;
}
