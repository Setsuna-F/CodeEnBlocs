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

void CodePageModel::removeBlock(){
	_blockList.removeFromIndex();
}

void CodePageModel::removeBlock(int i){
	_blockList.removeFromIndex(i);
}

BlockModel* CodePageModel::getBlock(int i){
	return _blockList.getBlockById(i);
}

void CodePageModel::flush(){
	//_blockList = *(new std::vector<BlockModel*>());
}

void CodePageModel::execute(){
	_blockList.execute();
}

std::vector<BlockModel*> CodePageModel::getBlockList(){
	return _blockList.getAllBlocks();
}
