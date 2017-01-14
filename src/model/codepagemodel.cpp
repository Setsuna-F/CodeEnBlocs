#include <vector>

#include "codepagemodel.hpp"

using namespace satap;

CodePageModel::CodePageModel(){}

CodePageModel::CodePageModel(std::vector<BlockModel*> blockList){
	_blockList = blockList;
}

void CodePageModel::addBlock(BlockModel* block){
	_blockList.setBlock(block, "");
}

void CodePageModel::addBlock(BlockModel* block, int i){
	_blockList.setBlock(block, "", i);
}


void CodePageModel::addBlock(BlockModel* block, satap::typeBloc t){
	_blockList.setBlock(block, t);
}


void CodePageModel::removeBlock(){
	_blockList.removeFromIndex();
}

void CodePageModel::removeBlock(int i){
	_blockList.removeFromIndex(i);
}

BlockModel* CodePageModel::getBlock(int i){
	return _blockList.getBlockById(i);
}


BlockModel* CodePageModel::getBlockByIndex(int i){
	return _blockList.getBlockByIndex(i);
}


void CodePageModel::flush(){
	//_blockList = *(new std::vector<BlockModel*>());
}

sct_type CodePageModel::execute(){
	return _blockList.execute();
}

std::vector<BlockModel*> CodePageModel::getBlockList(){
	return _blockList.getAllBlocks();
}

int CodePageModel::getNbBlock(int ligne) {
	return _blockList.getNbElements(ligne);
}

void CodePageModel::deleteLigne(int ligne) {
	//_blockList.removeFromIndex(ligne);
	_blockList.nullBlockFromIndex(ligne);
}
