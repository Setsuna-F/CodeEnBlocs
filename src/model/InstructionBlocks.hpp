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
		InstructionBlockModel();
		InstructionBlockModel(std::vector<BlockModel *> blockList);

		void setBlock		(BlockModel *block, std::string blockType, size_t startingId);
		void setBlock		(BlockModel *block, std::string blockType);
		void removeFromIndex();
		void removeFromIndex(size_t index);
		BlockModel*					getBlockById(size_t id);
		std::vector<BlockModel *>	getAllBlocks();
		sct_type					execute();
		int							getNbElements(int ligne);
	private:
		std::vector<BlockModel *> _blockList;
		std::vector<std::string > _blockListName;
	};
}


#endif /* InstructionBlocks_hpp */
