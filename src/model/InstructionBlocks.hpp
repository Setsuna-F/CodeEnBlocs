//
//  InstructionBlocks.hpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 11/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef InstructionBlocks_hpp
#define InstructionBlocks_hpp

#include <stdio.h>
#include "blockmodel.hpp"

namespace satap{

	class InstructionBlockModel : public BlockModel{
	public:
		InstructionBlockModel(){}
		InstructionBlockModel(std::vector<BlockModel *> blockList): _blockList(blockList){}
		
		void setBlock(BlockModel *block, std::string blockType, size_t startingId){
			_blockList.insert(_blockList.begin()+startingId,block);//j'insere un bloc a la position startingId.
			_blockListName.insert(_blockListName.begin()+startingId,blockType);//j'insere un bloc a la position startingId.
		}
		
		void removeFromIndex(size_t index){
			this->_blockList.erase(this->_blockList.begin() + index);
			this->_blockListName.erase(this->_blockListName.begin() + index);
		}
		
		
		BlockModel* getBlockById(size_t id){
			//std::cout<<"Inst: r0"<<std::endl;

			if (id==this->getId()){
			//	std::cout<<"Inst: r1"<<std::endl;
				return this;
			}

			BlockModel *block=nullptr;
			for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it){
			//	std::cout<<"Inst: "<<(*it)->getId()<<"="<<id<<std::endl;

				if ((*it)->getId() == id){
			//		std::cout<<"Inst: r2"<<std::endl;
					return *it;
				}
				else{
			//		std::cout<<"Inst: r3 "<< (*it)->strstr()<<std::endl;
					// /*block =*/ (*it)->execute();//getBlockById(id);
					block = (*it)->getBlockById(id);
				}
			}
			//std::cout<<"Inst: r4"<<std::endl;
			return block;
		}
		
		sct_type execute(){
			for (std::vector<BlockModel *>::iterator it = this->_blockList.begin(); it != this->_blockList.end(); ++it)
				sct_type condition = (*it)->execute();
		}
	private:
		std::vector<BlockModel *> _blockList;
		std::vector<std::string > _blockListName;
	};
	
}


#endif /* InstructionBlocks_hpp */
