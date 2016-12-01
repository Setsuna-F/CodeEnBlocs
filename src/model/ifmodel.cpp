#include "ifmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

IfModel::IfModel() {
	//
}

IfModel::IfModel(std::vector<BlockCompositeModel *> conditionList) {
	this->_conditionList = conditionList;
}

IfModel::IfModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockList) {
	this->_conditionList = conditionList;
	this->_blockList = blockList;
}


IfModel::~IfModel() {
	//
}

std::vector<BlockCompositeModel *> IfModel::getConditionList() {
	return this->_conditionList;
}

void IfModel::addCondtion(BlockCompositeModel * blockCM) {
	this->_conditionList.push_back(blockCM);
}

void IfModel::removeCondition(const int index) {
	this->_conditionList.erase(this->_conditionList.begin() + index);
}

std::vector<BlockModel *> IfModel::getBlockList() {
	return this->_blockList;
}

void IfModel::addBlock(BlockModel * block) {
	this->_blockList.push_back(block);
}

void IfModel::removeBlock(const int index) {
	this->_blockList.erase(this->_blockList.begin() + index);
}


std::string IfModel::execute() {
	std::string returnValue = "IfModel class";
	std::string condition_str = "true";

	for (std::vector<BlockCompositeModel *>::iterator it = this->_conditionList.begin(); it != this->_conditionList.end(); ++it) {
		condition_str = (condition_str == (*it)->execute()) ? "true" : "false";
	}

	if (condition_str == "true") {
		for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it) {
			returnValue = (*it)->execute();
		}
	}
	return returnValue;
}
