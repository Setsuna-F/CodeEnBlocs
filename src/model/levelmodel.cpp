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
	_description(""),
	_help		(""),
	_optimalBlocCount(optimalBlockCount),
	_workspace	(new WorkspaceModel()),
	_codePage	(new CodePageModel()){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description):
	_name		(name),
	_description(description),
	_help		(""),
	_optimalBlocCount(optimalBlockCount),
	_workspace	(new WorkspaceModel()),
	_codePage	(new CodePageModel()){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help):
	_name		(name),
	_description(description),
	_help		(help),
	_optimalBlocCount(optimalBlockCount),
	_workspace	(new WorkspaceModel()),
	_codePage	(new CodePageModel()){}


LevelModel::LevelModel(std::string name, int optimalBlockCount, std::string description, InstructionBlockModel availableBlocks):
	_name		(name),
	_description(description),
	_help		(""),
	_optimalBlocCount(optimalBlockCount),
	_availableBlocks(availableBlocks),
	_workspace	(new WorkspaceModel()),
	_codePage	(new CodePageModel()){}


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
	int score = 1;
	std::string out, outExpected;
	sct_type val_exec = _codePage->execute();


	std::cout << "coucou coucou coucou coucou" << std::endl;
	if(val_exec.int_type == nullptr && val_exec.bool_type == nullptr && val_exec.double_type == nullptr)
		return 0;

	std::cout << "coucou coucou coucou coucou" << std::endl;
	OutputListModel* outputList = _workspace->getOutputList();
	int expectedSize = _outputListExpected.size();
	int size = outputList->size();

	std::cout << "coucou coucou coucou coucou" << std::endl;
	//std::cout << "size :" << size<< "     Output :" << outputList->getValByIndex(0) << "     OutputExpected :" << _outputListExpected.getValByIndex(0) << std::endl;

	if (size != expectedSize) {
		return 0;
	}
	std::cout << "coucou coucou coucou coucou" << std::endl;
	for (int i = 0; i < size; i++) {
		out = outputList->getValByIndex(i);
		outExpected = _outputListExpected.getValByIndex(i);
		if(out != outExpected)
			return 0;
	}

	if(size<2*_optimalBlocCount+1)
		score++;
	if(size<_optimalBlocCount+1)
		score++;
	return score;
}
