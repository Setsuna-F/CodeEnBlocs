#include "levelmodel.hpp"

using namespace satap;

LevelModel::LevelModel(){
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name){
	_name = name;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, std::string description){
	_name = name;
	_description = description;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, std::string description, std::string help){
	_name = name;
	_description = description;
	_help = help;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, std::string description, std::vector<BlockModel*> availableBlocks){
	_name = name;
	_description = description;
	_availableBlocks = availableBlocks;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, std::string description, std::string help, std::vector<BlockModel*> availableBlocks){
	_name = name;
	_description = description;
	_help = help;
	_availableBlocks = availableBlocks;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

std::string LevelModel::getName(){
	return _name;
}

std::string LevelModel::getDescription(){
	return _description;
}

std::string LevelModel::getHelp(){
	return _help;
}

std::vector<BlockModel*> LevelModel::getAvailableBlocks(){
	return _availableBlocks;
}

OutputListModel LevelModel::getOutputListExpected(){
	return _outputListExpected;
}

WorkspaceModel* LevelModel::getWorkspace(){
	return _workspace;
}

CodePageModel* LevelModel::getCodePage(){
	return _codePage;
}

void LevelModel::setCodePage(CodePageModel* codePage){
	_codePage = codePage;
}

bool LevelModel::validate(){
	_codePage->execute();
	OutputListModel* outputList = _workspace->getOutputList();
	int expectedSize = _outputListExpected.size();
	int size = outputList->size();
	if(size != expectedSize)
		return false;
	return std::equal(_outputListExpected.getOutputList().begin(), _outputListExpected.getOutputList().begin() + expectedSize, outputList->getOutputList().begin());
}
