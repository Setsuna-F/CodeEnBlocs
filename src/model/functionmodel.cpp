#include <iostream>
#include <string>
#include "functionmodel.hpp"

using namespace satap;

FunctionModel::FunctionModel(std::string name, std::vector<BlockCompositeModel*> blockList){
	_name = name;
	_blockList = blockList;
}

FunctionModel::FunctionModel(std::string name, std::vector<BlockCompositeModel*> blockList, std::vector<VariableModel> parameterList){
	_name = name;
	_blockList = blockList;
	_parameterList = parameterList;
}

std::string FunctionModel::getCategory(){
	return "other";
}

sct_type FunctionModel::execute(){
	//std::string returnValue;
	//for(std::vector<BlockCompositeModel*>::iterator it = _blockList.begin(); it != _blockList.end(); ++it) {
	//	returnValue = (*it)->execute();
	//}
	sct_type res;
	return res;
}
