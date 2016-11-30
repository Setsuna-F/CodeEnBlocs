#ifndef FUNCTIONMODEL_HPP
#define FUNCTIONMODEL_HPP

#include <iostream>
#include <string>
#include "variablemodel.hpp"
#include "blockcompositemodel.hpp"

namespace satap{

	class FunctionModel : public BlockCompositeModel{
	
		public:
			FunctionModel(std::string name, std::vector<BlockCompositeModel> blockList);
			FunctionModel(std::string name, std::vector<BlockCompositeModel> blockList, std::vector<VariableModel> parameterList);
			//TODO : constructor with any number of variables and at least one block, automatically detects what is a variable and what is a block 
			
			
			
			std::string execute();
			
		private:
			//name
			std::string _name;
		
			//parameters
			std::vector<VariableModel> _parameterList;

			//block list
			std::vector<BlockCompositeModel> _blockList;
			
			//return variable
			VariableModel _returnValue;
	
	};

}

#endif
