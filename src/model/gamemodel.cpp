#include "gamemodel.hpp"
#include "iolevelmodel.hpp"
#include "additionlevelmodel.hpp"
#include "additionslevelmodel.hpp"

using namespace satap;

GameModel::GameModel(){
	_levelList.push_back(new IOLevelModel());
	_levelList.push_back(new AdditionLevelModel());
	_levelList.push_back(new AdditionsLevelModel());
}

std::vector<LevelModel*> GameModel::getLevelList(){
	return _levelList;
}

LevelModel* GameModel::getLevel(int i){
	return _levelList[i];
}

LevelModel* GameModel::getCurrentLevel(){
	return _currentLevel;
}

void GameModel::loadLevel(int i){
	_currentLevel = _levelList[i];
	_currentLevel->reset();
}
