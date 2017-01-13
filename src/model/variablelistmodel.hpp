//
//  variablelistmodel.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 01/11/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef variablelistmodel_hpp
#define variablelistmodel_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>

#include "variablemodel.hpp"

namespace satap{

	class VariableListModel{
		public:
			VariableModel*	getVariableModel(std::string name);
			void			setVariableModel(VariableModel variable);
			void			setVariable		(std::string name, sct_type value);
			void			setVariable		(sct_type value);
			bool			removeValue		(std::string name);
			sct_type		getValue		(std::string);
			size_t			size			();
			std::string		toString		();
		private:
		std::unordered_map<std::string, sct_type> _varlist;
	};
	
}

#endif /* variablelistmodel_hpp */
