//
//  InstructionBlocks.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 11/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "InstructionBlocks.hpp"

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


void InstructionBlockModel::removeFromIndex(size_t index){
	this->_blockList.erase(this->_blockList.begin() + index);
	this->_blockListName.erase(this->_blockListName.begin() + index);
}

void InstructionBlockModel::removeFromIndex(){
	this->_blockList.pop_back();
	this->_blockListName.pop_back();
}


BlockModel* InstructionBlockModel::getBlockById(size_t id){
	if (id==this->getId()){
		return this;
	}
	
	BlockModel *block=nullptr;
	for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it){
		
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
	for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it)
		condition = (*it)->execute();
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
