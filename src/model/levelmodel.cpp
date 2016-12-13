#include "levelmodel.hpp"

using namespace satap;

LevelModel::LevelModel():
	_name		(""),
	_description(""),
	_help		(""),
	_workspace(new WorkspaceModel()),
	_codePage (new CodePageModel()){}


LevelModel::LevelModel(std::string name, int optimalBlockCount):
	_name		(name),
	_optimalBlocCount(optimalBlockCount),
	_description(""),
	_help		(""),
	_workspace	(new WorkspaceModel()),
	_codePage	(new CodePageModel()){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description):
	_name		(name),
	_description(description),
	_help		(""),
	_codePage	(new CodePageModel()),
	_workspace	(new WorkspaceModel()),
	_optimalBlocCount(optimalBlockCount){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help):
	_name		(name),
	_description(description),
	_codePage	(new CodePageModel()),
	_workspace	(new WorkspaceModel()),
	_help		(help),
	_optimalBlocCount(optimalBlockCount){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, InstructionBlockModel availableBlocks):
	_name		(name),
	_description(description),
	_codePage	(new CodePageModel()),
	_workspace	(new WorkspaceModel()),
	_help		(""),
	_optimalBlocCount(optimalBlockCount),
	_availableBlocks(availableBlocks){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help, InstructionBlockModel availableBlocks){
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

InstructionBlockModel LevelModel::getAvailableBlocks(){
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

	// CA RETOURNE UNE EXCEPTION
	//if ((size != expectedSize) || !(std::equal(_outputListExpected.getOutputList().begin(), _outputListExpected.getOutputList().begin() + expectedSize, outputList->getOutputList().begin())))
	//	return 0;
	if (size != expectedSize) {
		for (int i = 0; i < size; i++) {
			std::string out = outputList->getValByIndex(i);
			std::string outExpected = _outputListExpected.getValByIndex(i);
		}
	}
	

	int score = 1;
	if(size<2*_optimalBlocCount+1)
		score++;
	if(size<_optimalBlocCount+1)
		score++;
	return score;
}
