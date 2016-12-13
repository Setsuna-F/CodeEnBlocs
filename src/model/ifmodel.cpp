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

IfModel::IfModel(std::vector<BlockCompositeModel *> conditionList, InstructionBlockModel blockList) {
	this->_conditionList = conditionList;
	this->_blockListTrue = blockList;
}

IfModel::IfModel(std::vector<BlockCompositeModel *> conditionList, InstructionBlockModel blockListtrue, InstructionBlockModel blockListfalse): _conditionList(conditionList), _blockListTrue(blockListtrue), _blockListFalse(blockListfalse) {
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

InstructionBlockModel IfModel::getBlockListTrue() {
	return this->_blockListTrue;
}

InstructionBlockModel IfModel::getBlockListFalse() {
	return this->_blockListFalse;
}

void IfModel::addBlockTrue(BlockModel * block) {
	this->_blockListTrue.setBlock(block, "");
}

void IfModel::addBlockFalse(BlockModel * block) {
	this->_blockListFalse.setBlock(block, "");
}

void IfModel::removeBlockTrue(const int index) {
	this->_blockListTrue.removeFromIndex(index);
}

void IfModel::removeBlockFalse(const int index) {
	this->_blockListFalse.removeFromIndex(index);
}



/* 
 Si je vois bien il y a ecrit: 
			si on a la condition vrai alors on execute les valeurs de _blockList.
			or _blockList est la liste des block du if mais ca ne dit pas si c'est la partie true ou si c'est la partie false.
	pour palier a cet erreur je propose de creer 2 attributs:
		_blockListTrue //liste des blocs a executer si la condition est vrai
		_blockListFase //liste des blocs a executer si la condition est fausse
 */
sct_type IfModel::execute() {
	std::string returnValue = "IfModel class";
	std::string condition_str = "true";
	sct_type result;
	result.int_type			=nullptr;
	result.double_type		=nullptr;
	result.bool_type		=nullptr;
	bool condition 			=true;
	
	for (std::vector<BlockCompositeModel *>::iterator it = this->_conditionList.begin(); it != this->_conditionList.end(); ++it) {
		condition = condition && (*it)->execute().double_type;
	}

	if (condition == true) {
		return this->_blockListTrue.execute();
	}
	
	else {
		return this->_blockListFalse.execute();
	}
	
	result.int_type			=nullptr;
	result.double_type		=nullptr;
	result.bool_type 		=nullptr;
	return result;
}

