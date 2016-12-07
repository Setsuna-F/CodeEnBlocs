#include "workspacemodel.hpp"

using namespace satap;

WorkspaceModel::WorkspaceModel(){}

WorkspaceModel::WorkspaceModel(InputListModel inputList, OutputListModel outputList, VariableListModel variableList, CodePageModel* codePage){
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

CodePageModel* WorkspaceModel::getCodePage(){
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

void WorkspaceModel::setCodePage(CodePageModel* codePage){
	_codePage = codePage;
}

void WorkspaceModel::executeCodePage(){ //TODO
	std::vector<BlockModel*> blockList = _codePage->getBlockList();
	//std::string returnValue;
	for(std::vector<BlockModel*>::iterator it = blockList.begin(); it != blockList.end(); ++it) {
		/*returnValue = */(*it)->execute();
	}
}

void WorkspaceModel::flush(){
	_inputList = *(new InputListModel());
	_outputList = *(new OutputListModel());
	_variableList = *(new VariableListModel());
	_codePage = new CodePageModel();
}
