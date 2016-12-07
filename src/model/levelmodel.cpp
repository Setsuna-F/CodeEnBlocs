#include "levelmodel.hpp"

using namespace satap;

LevelModel::LevelModel(){}

LevelModel::LevelModel(std::string name){
	_name = name;
}

std::string LevelModel::getName(){
	return _name;
}

OutputListModel LevelModel::getOutputListExpected(){
	return _outputListExpected;
}

bool LevelModel::isCompleted(WorkspaceModel workspace){
	return isCompleted(workspace.getOutputList());
}

bool LevelModel::isCompleted(OutputListModel outputList){
	int expectedSize = _outputListExpected.size();
	int size = outputList.size();
	if(size != expectedSize)
		return false;
	return std::equal(_outputListExpected.getOutputList().begin(), _outputListExpected.getOutputList().begin() + expectedSize, outputList.getOutputList().begin());
}
