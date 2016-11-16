//
//  variableList.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef variableList_hpp
#define variableList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>


class VariableList{
private:
	std::unordered_map<std::string, std::string> varlist;
public:
	void		setVariable	(std::string name, std::string value);
	void		setVariable	(std::string value);
	std::string getValue	(std::string);
	bool		removeValue	(std::string name);
	size_t		size		();
};

#endif /* variableList_hpp */
