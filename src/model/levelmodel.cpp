#include "levelmodel.hpp"

using namespace satap;

LevelModel::LevelModel(){
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, int optimalBlockCount){
	_name = name;
	_optimalBlocCount = optimalBlockCount;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description){
	_name = name;
	_optimalBlocCount = optimalBlockCount;
	_description = description;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help){
	_name = name;
	_optimalBlocCount = optimalBlockCount;
	_description = description;
	_help = help;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, std::vector<BlockModel*> availableBlocks){
	_name = name;
	_optimalBlocCount = optimalBlockCount;
	_description = description;
	_availableBlocks = availableBlocks;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help, std::vector<BlockModel*> availableBlocks){
	_name = name;
	_optimalBlocCount = optimalBlockCount;
	_description = description;
	_help = help;
	_availableBlocks = availableBlocks;
	_workspace = new WorkspaceModel();
	_codePage = new CodePageModel();
}

std::string LevelModel::getName(){
	return _name;
}

int LevelModel::getOptimalBlocCount(){
	return _optimalBlocCount;
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

int LevelModel::validate(){ //TODO à tester
	_codePage->execute();
	OutputListModel* outputList = _workspace->getOutputList();
	int expectedSize = _outputListExpected.size();
	int size = outputList->size();
	if((size != expectedSize) || !(std::equal(_outputListExpected.getOutputList().begin(), _outputListExpected.getOutputList().begin() + expectedSize, outputList->getOutputList().begin())))
		return 0;
	int score = 1;
	if(size<2*_optimalBlocCount+1)
		score++;
	if(size<_optimalBlocCount+1)
		score++;
	return score;
}
