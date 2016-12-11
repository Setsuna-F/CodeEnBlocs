#include <vector>

#include "codepagemodel.hpp"

using namespace satap;

CodePageModel::CodePageModel(){}

CodePageModel::CodePageModel(std::vector<BlockModel*> blockList){
	_blockList = blockList;
}

void CodePageModel::addBlock(BlockModel* block){
	_blockList.push_back(block);
}

void CodePageModel::addBlock(BlockModel* block, int i){
	_blockList.insert(_blockList.begin()+i, block);
}

void CodePageModel::removeBlock(){
	_blockList.pop_back();
}

void CodePageModel::removeBlock(int i){
	_blockList.erase(_blockList.begin()+i);
}

BlockModel* CodePageModel::getBlock(int i){
	return _blockList[i];
}

void CodePageModel::flush(){
	_blockList = *(new std::vector<BlockModel*>());
}

void CodePageModel::execute(){
	for(int i=0; i<(int)_blockList.size(); i++){
		_blockList[i]->execute();
	}
}

std::vector<BlockModel*> CodePageModel::getBlockList(){
	return _blockList;
}
