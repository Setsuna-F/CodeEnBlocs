//
//  InstructionBlocks.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 11/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "InstructionBlocks.hpp"
#include "AssignmentModel.hpp"
using namespace satap;

InstructionBlockModel::InstructionBlockModel(){}

InstructionBlockModel::InstructionBlockModel(std::vector<BlockModel *> blockList): _blockList(blockList){}

void InstructionBlockModel::setBlock(BlockModel *block, std::string blockType, size_t startingId){
	_blockList.insert(_blockList.begin()+startingId,block);//j'insere un bloc a la position startingId.
	_blockListName.insert(_blockListName.begin()+startingId,blockType);//j'insere un bloc a la position startingId.
}
void InstructionBlockModel::setBlock(BlockModel *block, std::string blockType){
	_blockList.push_back(block);
	_blockListName.push_back(blockType);
}

void InstructionBlockModel::setBlock(BlockModel *block, satap::typeBloc t){
	block->setType(t);
	_blockList.push_back(block);
	_typeList.push_back(t);
}


void InstructionBlockModel::removeFromIndex(size_t index){
	this->_blockList.erase(this->_blockList.begin() + index);
	this->_blockListName.erase(this->_blockListName.begin() + index);
}

void InstructionBlockModel::removeFromIndex(){
	this->_blockList.pop_back();
	this->_blockListName.pop_back();
}


/**
 * \brief   permet d'avoir recuperer un pointeur sur un BlockModel
 * 			depuis la position dans le vecteur de BlockModel.
 *
 * \param index est le numero de la position d'un bloc dans le vecteur de BlockModel.
 *
 * \return un pointeur sur un BlockModel qui se trouve dans le vecteur de BlockModel.
 */
BlockModel* InstructionBlockModel::getBlockByIndex(size_t index){
	if(this->_blockList.size()<index) //Si index est plus grand que la tille du tableau en lui meme
		return NULL; //On retourne null

	return this->_blockList[index];
}


BlockModel* InstructionBlockModel::getBlockById(size_t id){
	if (id==this->getId()){
		return this;
	}

	BlockModel *block=nullptr;
	for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it){
		//std::cout<<"it->id = "<< (*it)->getId() <<std::endl;
		if ((*it)->getId() == id){
			return *it;
		}
		else{
			block = (*it)->getBlockById(id);
		}
	}
	return block;
}

std::vector<BlockModel *> InstructionBlockModel::getAllBlocks(){
	return _blockList;
}


sct_type InstructionBlockModel::execute(){
	sct_type condition;

	for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it){
		//condition = (*it)->execute();
		if((*it)->getType() == AssignementBlocType){
			AssignmentModel* assignModel = dynamic_cast<AssignmentModel*>(*it);
			condition = assignModel->execute();
			/*if(condition.int_type!=nullptr)	{
				std::cout<< "fichier : " << __FILE__ << std::endl << " fonction : "<< __FUNCTION__ << std::endl;
				std::cout<< "val : " << *condition.int_type << std::endl;
				std::cout<< "-----------------------------------" << std::endl;
			}
			else if(condition.double_type!=nullptr)	{
				std::cout<< "fichier : " << __FILE__ << " fonction : "<< __FUNCTION__ << std::endl;
				std::cout<< "val : " << *condition.double_type << std::endl;
				std::cout<< "-----------------------------------" << std::endl;
			}
			else if(condition.bool_type!=nullptr)	{
				std::cout<< "fichier : " << __FILE__ << " fonction : "<< __FUNCTION__ << std::endl;
				std::cout<< "val : " << *condition.bool_type << std::endl;
				std::cout<< "-----------------------------------" << std::endl;
			}
			else{
				std::cout<< "ERREUR: " << __FUNCTION__ << std::endl;
			}*/
		}
	}
	return condition;
}

int satap::InstructionBlockModel::getNbElements(int ligne)
{
	if (_blockList.size() <= ligne) {
		return 0;
	}
	else {
		return _blockList.at(ligne)->getNbElements();
	}
}
