#include <iostream>
#include <string>

#include "inputmodel.hpp"

using namespace satap;

InputModel::InputModel(): _inputList(new InputListModel()){}

InputModel::InputModel(InputListModel* inputList){
	_inputList = inputList;
}

void InputModel::setInputList(InputListModel* inputList){
	_inputList = inputList;
}

sct_type InputModel::execute(){
	sct_type res;
	res.int_type	= nullptr;
	res.double_type	= nullptr;
	res.bool_type	= nullptr;
	
	return _inputList?_inputList->pop():res;
}

typeBloc InputModel::getType() {
	return InputBlocType;
}