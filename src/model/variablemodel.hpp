//
//  variable.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef VARIABLEMODEL_HPP
#define VARIABLEMODEL_HPP

#include <iostream>
#include <string>
#include "blockcompositemodel.hpp"

namespace satap{

	class VariableModel : public BlockCompositeModel{
		
		public:
			VariableModel(std::string name="", std::string value="");
	
			void setName(std::string n);
			std::string getName();
	
			void setValue(std::string n);
			std::string getValue();
		
			std::string execute();
			
		private:
			//variable name
			std::string _name;
			//variable value
			std::string _value;
	};

}

#endif /* VARIABLEMODEL_HPP */
