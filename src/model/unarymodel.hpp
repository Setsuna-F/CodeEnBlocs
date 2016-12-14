#ifndef UNARYMODEL_HPP
#define UNARYMODEL_HPP
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

	class UnaryModel : public OperatorModel {

		public:
			UnaryModel();
			UnaryModel(BlockCompositeModel* operand);
			UnaryModel(const UnaryModel & unaryModel);
			~UnaryModel();
			BlockCompositeModel* getOperand();
			void setOperand(BlockCompositeModel* operand);
			virtual sct_type execute() = 0;
			int getNbElements();

		private:
			//operand
			BlockCompositeModel* _operand;
	};
}

#endif	// BINARYMODEL_HPP
