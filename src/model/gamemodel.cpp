#include "gamemodel.hpp"

using namespace satap;

GameModel::GameModel(){}

std::vector<LevelModel> GameModel::getLevelList(){
	return _levelList;
}

LevelModel GameModel::getLevel(int i){
	return _levelList[i];
}

void GameModel::loadLevel(int i){
	_workspace.flush();
	_currentLevel = _levelList[i];
}

WorkspaceModel GameModel::getWorkspace(){
	return _workspace;
}
