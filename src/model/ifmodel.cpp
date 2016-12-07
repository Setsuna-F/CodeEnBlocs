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
	this->_blockListTrue = blockList;
}

IfModel::IfModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockListtrue, std::vector<BlockModel *> blockListfalse): _conditionList(conditionList), _blockListTrue(blockListtrue), _blockListFalse(blockListfalse) {

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

std::vector<BlockModel *> IfModel::getBlockListTrue() {
	return this->_blockListTrue;
}

std::vector<BlockModel *> IfModel::getBlockListFalse() {
	return this->_blockListFalse;
}

void IfModel::addBlockTrue(BlockModel * block) {
	this->_blockListTrue.push_back(block);
}

void IfModel::addBlockFalse(BlockModel * block) {
	this->_blockListFalse.push_back(block);
}

void IfModel::removeBlockTrue(const int index) {
	this->_blockListTrue.erase(this->_blockListTrue.begin() + index);
}

void IfModel::removeBlockFalse(const int index) {
	this->_blockListFalse.erase(this->_blockListFalse.begin() + index);
}



/*
 2 problemes
 -----------
 
 1_ Pourquoi mettre un retour en string si on veut retourner un booleen ?
 faisont en sorte qu'il retourne bool et non string
 
 2_ Si je vois bien il y a ecrit: 
			si on a la condition vrai alors on execute les valeurs de _blockList.
			or _blockList est la liste des block du if mais ca ne dit pas si c'est la partie true ou si c'est la partie false.
	pour palier a cet erreur je propose de creer 2 attributs:
		_blockListTrue //liste des blocs a executer si la condition est vrai
		_blockListFase //liste des blocs a executer si la condition est fausse
 */
sct_type IfModel::execute() {
	std::string returnValue = "IfModel class";
	std::string condition_str = "true";

	for (std::vector<BlockCompositeModel *>::iterator it = this->_conditionList.begin(); it != this->_conditionList.end(); ++it) {
		//condition_str = (condition_str == (*it)->execute()) ? "true" : "false";
	}

	if (condition_str == "true") {
		for (std::vector<BlockModel *>::iterator it = this->_blockListTrue.begin(); it != this->_blockListTrue.end(); ++it) {
			//returnValue = (*it)->execute();
		}
	}
	else{
		for (std::vector<BlockModel *>::iterator it = this->_blockListFalse.begin(); it != this->_blockListFalse.end(); ++it) {
			//returnValue = (*it)->execute();
		}
	}
	sct_type res;
	return res;
}




/*
 Mais a quoi sert cette methode ? :x
 */
std::string IfModel::getCategory() {
	return "conditional";
}
