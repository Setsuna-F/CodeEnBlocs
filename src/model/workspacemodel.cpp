#include "workspacemodel.hpp"

using namespace satap;

WorkspaceModel::WorkspaceModel(){}

WorkspaceModel::WorkspaceModel(InputListModel inputList, OutputListModel outputList, VariableListModel variableList, CodePageModel codePage){
	_inputList = inputList;
	_outputList = outputList;
	_variableList = variableList;
	_codePage = codePage;
}

InputListModel WorkspaceModel::getInputList(){
	return _inputList;
}

OutputListModel WorkspaceModel::getOutputList(){
	return _outputList;
}

VariableListModel WorkspaceModel::getVariableList(){
	return _variableList;
}

CodePageModel WorkspaceModel::getCodePage(){
	return _codePage;
}

void WorkspaceModel::setInputList(InputListModel inputList){
	_inputList = inputList;
}

void WorkspaceModel::setOutputList(OutputListModel outputList){
	_outputList = outputList;
}

void WorkspaceModel::setVariableList(VariableListModel variableList){
	_variableList = variableList;
}

void WorkspaceModel::setCodePage(CodePageModel codePage){
	_codePage = codePage;
}
