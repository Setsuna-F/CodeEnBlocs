#ifndef LOOPMODEL_HPP
#define LOOPMODEL_HPP
#include "blocksimplemodel.hpp"
#include "blockcompositemodel.hpp"
#include "tools.h"
/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class LoopModel : public BlockSimpleModel {

		public:
			LoopModel();
			LoopModel(std::vector<BlockCompositeModel *> conditionList);
			LoopModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockList);
			~LoopModel();
			std::vector<BlockCompositeModel *> getConditionList();
			void addCondtion(BlockCompositeModel * blockCM);
			void removeCondition(const int index);
			std::vector<BlockModel *> getBlockList();
			void addBlock(BlockModel * block);
			void removeBlock(const int index);
			sct_type execute();

		private:
			//Conditions and / or parameters of the loop
			std::vector<BlockCompositeModel *> _conditionList;

			//block list
			std::vector<BlockModel *> _blockList;
	};
}

#endif	// LOOPMODEL_HPP
