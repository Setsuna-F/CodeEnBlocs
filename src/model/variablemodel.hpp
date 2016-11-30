//
//  variable.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef variablemode_hpp
#define variablemodel_hpp

#include <stdio.h>
#include <iostream>

namespace satap{

	class VariableModel{
	private:
		std::string _name;
		std::string _value;
	public:
		VariableModel(std::string name="", std::string value="");
	
		void setName(std::string n);
		std::string getName();
	
		void setValue(std::string n);
		std::string getValue();
	};

}

#endif /* variablemodel_hpp */
