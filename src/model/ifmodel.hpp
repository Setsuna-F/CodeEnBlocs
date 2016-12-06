#ifndef IFMODEL_HPP
#define IFMODEL_HPP
#include "blocksimplemodel.hpp"
#include "blockcompositemodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class IfModel : public BlockSimpleModel {

		public:
			IfModel();
			IfModel(std::vector<BlockCompositeModel *> conditionList);
			IfModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockList);
			~IfModel();
			std::vector<BlockCompositeModel *> getConditionList();
			void addCondtion(BlockCompositeModel * blockCM);
			void removeCondition(const int index);
			std::vector<BlockModel *> getBlockList();
			void addBlock(BlockModel * block);
			void removeBlock(const int index);
			std::string execute();
			std::string getCategory();

		private:
			//Conditions and / or parameters of the if
			std::vector<BlockCompositeModel *> _conditionList;

			//block list
			std::vector<BlockModel *> _blockList;
	};
}

#endif	// IFMODEL_HPP
