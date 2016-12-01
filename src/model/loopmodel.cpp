#include "loopmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

LoopModel::LoopModel() {
	//
}

LoopModel::LoopModel(std::vector<BlockCompositeModel *> conditionList) {
	this->_conditionList = conditionList;
}

LoopModel::LoopModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockList) {
	this->_conditionList = conditionList;
	this->_blockList = blockList;
}

LoopModel::~LoopModel() {
	//
}

std::vector<BlockCompositeModel *> LoopModel::getConditionList() {
	return this->_conditionList;
}

void LoopModel::addCondtion(BlockCompositeModel * blockCM) {
	this->_conditionList.push_back(blockCM);
}

void LoopModel::removeCondition(const int index) {
	this->_conditionList.erase(this->_conditionList.begin() + index);
}

std::vector<BlockModel *> LoopModel::getBlockList() {
	return this->_blockList;
}

void LoopModel::addBlock(BlockModel * block) {
	this->_blockList.push_back(block);
}

void LoopModel::removeBlock(const int index) {
	this->_blockList.erase(this->_blockList.begin() + index);
}

std::string LoopModel::execute() {
	std::string returnValue = "LoopModel class";
	return returnValue;
}
