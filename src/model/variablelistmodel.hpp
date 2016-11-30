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

namespace satap{

	class VariableListModel{
	private:
		std::unordered_map<std::string, std::string> _varlist;
	public:
		void		setVariable	(std::string name, std::string value);
		void		setVariable	(std::string value);
		std::string getValue	(std::string);
		bool		removeValue	(std::string name);
		size_t		size		();
	};
	
}

#endif /* variablelistmodel_hpp */
