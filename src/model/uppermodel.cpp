//
//  uppermodel.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 06/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "uppermodel.hpp"
#include "tools.h"

using namespace satap;

UpperModel::UpperModel() {
	//
}

UpperModel::UpperModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

UpperModel::UpperModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

UpperModel::~UpperModel() {
	//
}

sct_type UpperModel::execute() {
	sct_type firstOperand;
	firstOperand.int_type		=nullptr;
	firstOperand.double_type	=nullptr;
	firstOperand.bool_type		=nullptr;
	
	sct_type secondOperand;
	secondOperand.int_type		=nullptr;
	secondOperand.double_type	=nullptr;
	secondOperand.bool_type		=nullptr;
	
	bool res_bool=true;
	sct_type res;
	secondOperand.int_type		=nullptr;
	secondOperand.double_type	=nullptr;
	secondOperand.bool_type		=&res_bool;

	firstOperand = this->BinaryModel::getFirstOperand()->execute();
	secondOperand = this->BinaryModel::getSecondOperand()->execute();
	
	if(firstOperand.int_type && secondOperand.int_type){
		if(&firstOperand.int_type < &secondOperand.int_type){
			res_bool=false;
			res.bool_type=&res_bool;
		}
		return res;
	}
	else if(firstOperand.double_type && secondOperand.double_type){
		if(&firstOperand.double_type < &secondOperand.double_type){
			res_bool=false;
			res.bool_type=&res_bool;
		}
		return res;
	}
	else{
		res.bool_type=nullptr;
		return res;
	}
}

std::string UpperModel::getCategory() {
	return "other";
}
