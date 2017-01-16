#include "gamemodel.hpp"
#include "iolevelmodel.hpp"
#include "additionlevelmodel.hpp"
#include "additionslevelmodel.hpp"
#include "sublevelmodel.hpp"
#include "multlevelmodel.hpp"
#include "divlevelmodel.hpp"

using namespace satap;

GameModel::GameModel(){
	_levelList.push_back(new IOLevelModel());
	_levelList.push_back(new AdditionLevelModel());
	_levelList.push_back(new AdditionsLevelModel());
	_levelList.push_back(new SubLevelModel());
	_levelList.push_back(new MultLevelModel());
	_levelList.push_back(new DivLevelModel());
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
