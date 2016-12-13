#ifndef CODEPAGEMODEL_HPP
#define CODEPAGEMODEL_HPP

#include <vector>

#include "blockmodel.hpp"
#include "InstructionBlocks.hpp"

namespace satap {
	
	class CodePageModel{
		
		public:
			CodePageModel();
			CodePageModel(std::vector<BlockModel*> blockList);
			void addBlock(BlockModel* block);
			void addBlock(BlockModel* block, int i);
			void removeBlock();
			void removeBlock(int i);
			BlockModel* getBlock(int i);
			std::vector<BlockModel*> getBlockList();
			void flush();
			void execute();

		private:
			//std::vector<BlockModel*> _blockList;
			InstructionBlockModel _blockList;
	};
}

#endif
