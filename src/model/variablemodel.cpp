//
//  variablemodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "variablemodel.hpp"
#include "blockcompositemodel.hpp"

using namespace satap;

VariableModel::VariableModel(){}

VariableModel::VariableModel(std::string name, sct_type value): _name(name), _value(value){}

void VariableModel::setName(std::string n){
	_name = n;
}

std::string VariableModel::getName(){
	return _name;
}

void VariableModel::setValue(sct_type value){
	_value = value;
}

sct_type VariableModel::getValue(){
	return _value;
}

sct_type VariableModel::execute(){
	return _value;
}
