//
//  variable.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef variable_hpp
#define variable_hpp

#include <stdio.h>
#include <iostream>


class Variable{
private:
	std::string name;
	std::string value;
public:
	Variable(std::string name="", std::string value="");
	
	void setName(std::string n);
	std::string getName();
	
	void setValue(std::string n);
	std::string getValue();
};


#endif /* variable_hpp */
