//
//  variablelistmodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "variablelistmodel.hpp"

using namespace satap;

//TODO constructor

void VariableListModel::setVariableModel(VariableModel variable){
	_varlist[variable.getName()]=variable.getValue();
}



void VariableListModel::setVariable(std::string name, sct_type value){
	_varlist[name]=value;
}

void VariableListModel::setVariable(sct_type value){
	std::string name="";

	if(value.int_type)
		name=typeToString(value.int_type);
	else if(value.double_type)
		name=typeToString(value.double_type);
	else if(*value.bool_type==true)
		name="true";
	else
		name="false";
	_varlist[name]=value;
}

sct_type VariableListModel::getValue(std::string name){
	auto search = _varlist.find(name);
	if(search != _varlist.end() )
		return search->second;
	
	sct_type return_null;
	return_null.int_type	=nullptr;
	return_null.double_type=nullptr;
	return_null.bool_type	=nullptr;
	
	return return_null;
}


VariableModel* VariableListModel::getVariableModel(std::string name){
	auto search = _varlist.find(name);
	if(search != _varlist.end() )
		return new VariableModel(name, search->second); //search->second;
	return NULL;
}



bool VariableListModel::removeValue(std::string name){
	for(auto it = _varlist.begin(); it != _varlist.end(); )
		if(it->first == name){
			it = _varlist.erase(it);
			return true;
		}
		else
			++it;
	return false;
}

size_t VariableListModel::size(){
	return _varlist.size();
}

std::string satap::VariableListModel::toString()
{
	std::string s = "";
	for (auto var : _varlist) {
		std::string name = var.first;

		std::string value;
		if (var.second.bool_type)
			value = std::to_string(*var.second.bool_type);
		else if (var.second.double_type)
			value = std::to_string(*var.second.double_type);
		else if (var.second.int_type)
			value = std::to_string(*var.second.int_type);
		else
			value = "?";

		s += name + "=" + value + "\n";
	}
	return s;
}

void satap::VariableListModel::clear()
{
	_varlist.clear();
}



