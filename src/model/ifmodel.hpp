#ifndef IFMODEL_HPP
#define IFMODEL_HPP
#include "blocksimplemodel.hpp"
#include "blockcompositemodel.hpp"
#include "tools.h"
/*
 *
 * Description :
 *
 *
*/


/*
 Quelques erreurs: voir le .cpp
 */


namespace satap {

	class IfModel : public BlockSimpleModel {

		public:
			IfModel();
			IfModel(std::vector<BlockCompositeModel *> conditionList);
			IfModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockListtrue);
			IfModel(std::vector<BlockCompositeModel *> conditionList, std::vector<BlockModel *> blockListtrue, std::vector<BlockModel *> blockListfalse);
			~IfModel();
			std::vector<BlockCompositeModel *> getConditionList();
			void addCondtion		(BlockCompositeModel * blockCM);
			void removeCondition	(const int index);
			std::vector<BlockModel *> getBlockListTrue();
			std::vector<BlockModel *> getBlockListFalse();
			void addBlockTrue		(BlockModel * block);
			void addBlockFalse		(BlockModel * block);
			void removeBlockTrue	(const int index);
			void removeBlockFalse	(const int index);
			sct_type execute();
			std::string getCategory();

		private:
			//Conditions and / or parameters of the if
			std::vector<BlockCompositeModel *> _conditionList;

			//block list
			std::vector<BlockModel *> _blockListTrue;
			std::vector<BlockModel *> _blockListFalse;
	};
}

#endif	// IFMODEL_HPP
