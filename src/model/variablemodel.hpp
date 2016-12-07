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
#include "tools.h"

namespace satap{

	class VariableModel : public BlockCompositeModel{

		public:

			VariableModel(std::string name, sct_type value);
	
			void setName(std::string n);
			std::string getName();
	
			void setValue(sct_type n);
			sct_type getValue();
		
			sct_type execute();

		private:
			//variable name
			std::string _name;
		
			//variable value
			sct_type _value;
	};

}

#endif /* VARIABLEMODEL_HPP */
