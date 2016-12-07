#ifndef BINARYMODEL_HPP
#define BINARYMODEL_HPP
#include "operatormodel.hpp"
#include "blockcompositemodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class BinaryModel : public OperatorModel {
		
		public:
			BinaryModel();
			BinaryModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			BinaryModel(const BinaryModel & binaryModel);
			~BinaryModel();
			BlockCompositeModel* getFirstOperand();
			void setFirstOperand(BlockCompositeModel* operand);
			BlockCompositeModel* getSecondOperand();
			void setSecondOperand(BlockCompositeModel* operand);
			virtual sct_type execute() = 0;
			virtual std::string getCategory() = 0;
			
		private:
			//operand 1
			BlockCompositeModel* _firstOperand;
			//operand 2
			BlockCompositeModel* _secondOperand;
	};
}

#endif	// BINARYMODEL_HPP
