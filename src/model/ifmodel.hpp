#ifndef IFMODEL_HPP
#define IFMODEL_HPP
#include "blocksimplemodel.hpp"
#include "blockcompositemodel.hpp"
#include "InstructionBlocks.hpp"

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
			IfModel(std::vector<BlockCompositeModel *> conditionList, InstructionBlockModel blockListtrue);
			IfModel(std::vector<BlockCompositeModel *> conditionList, InstructionBlockModel blockListtrue, InstructionBlockModel blockListfalse);
			~IfModel();
			std::vector<BlockCompositeModel *> getConditionList();

			void addCondtion		(BlockCompositeModel * blockCM);
			void removeCondition	(const int index);
			InstructionBlockModel	getBlockListTrue();
			InstructionBlockModel	getBlockListFalse();
			void addBlockTrue		(BlockModel * block);
			void addBlockFalse		(BlockModel * block);
			void removeBlockTrue	(const int index);
			void removeBlockFalse	(const int index);
			sct_type execute();


		private:
			//Conditions and / or parameters of the if
			std::vector<BlockCompositeModel *> _conditionList;

			//block list
			InstructionBlockModel _blockListTrue;
			InstructionBlockModel _blockListFalse;
	};
}

#endif	// IFMODEL_HPP
