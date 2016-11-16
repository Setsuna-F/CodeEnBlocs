//
//  variableList.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "variableList.hpp"


void VariableList::setVariable(std::string name, std::string value){
	varlist[name]=value;
}

void VariableList::setVariable(std::string value){
	varlist[value]=value;
}

std::string VariableList::getValue(std::string name){
	auto search = varlist.find(name);
	if(search != varlist.end() )
		return search->second;
	return "";
}

bool VariableList::removeValue(std::string name){
	for(auto it = varlist.begin(); it != varlist.end(); )
		if(it->first == name){
			it = varlist.erase(it);
			return true;
		}
		else
			++it;
	return false;
}

size_t VariableList::size(){
	return varlist.size();
}



