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
			void addBlock(BlockModel* block, satap::typeBloc t);
			void addBlock(BlockModel* block, satap::typeBloc t, size_t lineNumber);
			void removeBlock();
			void removeBlock(int i);
			int getNbBlock(int ligne);
			void deleteLigne(int ligne);
			BlockModel* getBlock(int i);
			BlockModel* getBlockByIndex(int i);
			std::vector<BlockModel*> getBlockList();
			void flush();
			sct_type execute();

		private:
			//std::vector<BlockModel*> _blockList;
			InstructionBlockModel _blockList;
	};
}

#endif
