#include "workspacemodel.hpp"
#include "inputlistmodel.hpp"

using namespace satap;

WorkspaceModel::WorkspaceModel(){
	_inputList = new InputListModel();
	_outputList = new OutputListModel();
	_variableList = new VariableListModel();
}

WorkspaceModel::WorkspaceModel(InputListModel* inputList, OutputListModel* outputList, VariableListModel* variableList){
	_inputList = inputList;
	_outputList = outputList;
	_variableList = variableList;
}

InputListModel* WorkspaceModel::getInputList(){
	return _inputList;
}

OutputListModel* WorkspaceModel::getOutputList(){
	return _outputList;
}

VariableListModel* WorkspaceModel::getVariableList(){
	return _variableList;
}

void WorkspaceModel::setInputList(InputListModel* inputList){
	_inputList = inputList;
}

void WorkspaceModel::setOutputList(OutputListModel* outputList){
	_outputList = outputList;
}

void WorkspaceModel::setVariableList(VariableListModel* variableList){
	_variableList = variableList;
}

void WorkspaceModel::flush(){
	_inputList->clear();
	_outputList->clear();
	_variableList->clear();
}

void satap::WorkspaceModel::reload()
{
	_inputList->reload();
	_outputList->clear();
	_variableList->clear();
}


