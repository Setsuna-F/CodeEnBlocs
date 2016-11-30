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

void VariableListModel::setVariable(std::string name, std::string value){
	_varlist[name]=value;
}

void VariableListModel::setVariable(std::string value){
	_varlist[value]=value;
}

std::string VariableListModel::getValue(std::string name){
	auto search = _varlist.find(name);
	if(search != _varlist.end() )
		return search->second;
	return "";
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



