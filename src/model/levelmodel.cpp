#include "levelmodel.hpp"

using namespace satap;

LevelModel::LevelModel(){}

LevelModel::LevelModel(std::string name){
	_name = name;
}

LevelModel::LevelModel(std::string name, std::string description){
	_name = name;
	_description = description;
}

std::string LevelModel::getName(){
	return _name;
}

std::string LevelModel::getDescription(){
	return _description;
}

OutputListModel LevelModel::getOutputListExpected(){
	return _outputListExpected;
}

WorkspaceModel LevelModel::getWorkspace(){
	return _workspace;
}

bool LevelModel::validate(){
	_workspace.executeCodePage();
	OutputListModel outputList = _workspace.getOutputList();
	int expectedSize = _outputListExpected.size();
	int size = outputList.size();
	if(size != expectedSize)
		return false;
	return std::equal(_outputListExpected.getOutputList().begin(), _outputListExpected.getOutputList().begin() + expectedSize, outputList.getOutputList().begin());
}
