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

			VariableModel();
			VariableModel(std::string name, sct_type value);
	
			void setName(std::string n);
			std::string getName();

			void setValue(sct_type n);
			void setValuePtr(sct_type* n);
			sct_type getValue();
			sct_type* VariableModel::getValuePtr();
		
			sct_type execute();
			typeBloc getType();




		private:
			//variable name
			std::string _name;
		
			//variable value
			sct_type _value;
			sct_type* _value_ptr;
	};

}

#endif /* VARIABLEMODEL_HPP */
