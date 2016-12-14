#ifndef BINARYMODEL_HPP
#define BINARYMODEL_HPP
#include "operatormodel.hpp"
#include "blockcompositemodel.hpp"

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
			int getNbElements();
		protected:
			//operand gauche
			BlockCompositeModel* _firstOperand;
			//operand droite
			BlockCompositeModel* _secondOperand;
	};
}

#endif	// BINARYMODEL_HPP
