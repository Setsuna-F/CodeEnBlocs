#include <iostream>
#include <string>

#include "inputmodel.hpp"

using namespace satap;

InputModel::InputModel(){}

InputModel::InputModel(InputListModel inputList){
	_inputList = inputList;
}

void InputModel::setInputList(InputListModel inputList){
	_inputList = inputList;
}

std::string InputModel::getCategory(){
	return "other";
}

sct_type InputModel::execute(){
	return _inputList.pop();
}
