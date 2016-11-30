#include <iostream>
#include <string>
#include "functionmodel.hpp"

using namespace satap;

FunctionModel::FunctionModel(std::string name, std::vector<BlockCompositeModel> blockList){
	_name = name;
	_blockList = blockList;
}

FunctionModel::FunctionModel(std::string name, std::vector<BlockCompositeModel> blockList, std::vector<VariableModel> parameterList){
	_name = name;
	_blockList = blockList;
	_parameterList = parameterList;
}
			
std::string FunctionModel::execute(){
	for (int i=0; i < _blockList.size(); i++) {
		_blockList[i].execute();
	}
}
