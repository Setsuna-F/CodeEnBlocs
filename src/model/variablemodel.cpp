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


VariableModel::VariableModel() : _name(), _value(), _value_ptr()
{
	_value_ptr = new sct_type();
}

VariableModel::VariableModel(std::string name, sct_type value) : _name(name), _value(value), _value_ptr()
{
	_value_ptr = new sct_type();
}

void VariableModel::setName(std::string n) {
	_name = n;
}

std::string VariableModel::getName() {
	return _name;
}

void VariableModel::setValue(sct_type value) {
	_value = value;
	std::cout << "setvalue begin" << std::endl;
	if (value.bool_type != nullptr)
	{
		if (_value_ptr->bool_type == nullptr)
			_value_ptr->bool_type = new bool(*value.bool_type);
		else
			*_value_ptr->bool_type = *value.bool_type;
	}
	else
		_value_ptr->bool_type = nullptr;

	if (value.int_type != nullptr)
	{
		if (_value_ptr->int_type == nullptr)
			_value_ptr->int_type = new int(*value.int_type);
		else
			*_value_ptr->int_type = *value.int_type;
	}
	else
		_value_ptr->int_type = nullptr;

	if (value.double_type != nullptr)
	{
		if (_value_ptr->double_type == nullptr)
			_value_ptr->double_type = new double(*value.double_type);
		else
			*_value_ptr->double_type = *value.double_type;
	}
	else
		_value_ptr->double_type = nullptr;
}

void satap::VariableModel::setValuePtr(sct_type * n)
{
	_value_ptr = n;
}

sct_type VariableModel::getValue() {
	//return _value;
	return *_value_ptr;
}

sct_type* VariableModel::getValuePtr() {
	return _value_ptr;
}

sct_type VariableModel::execute() {
	//return _value;
	std::cout << "execute begin" << std::endl;
	if (_value_ptr->int_type != nullptr)
		std::cout << "int : " << *_value_ptr->int_type << std::endl;
	if (_value_ptr->double_type != nullptr)
		std::cout << "double : " << *_value_ptr->double_type << std::endl;
	if (_value_ptr->bool_type != nullptr)
		std::cout << "bool : " << *_value_ptr->bool_type << std::endl;
	std::cout << "execute end" << std::endl;
	return *_value_ptr;
}

typeBloc VariableModel::getType()
{
	return VariableBlocType;
}