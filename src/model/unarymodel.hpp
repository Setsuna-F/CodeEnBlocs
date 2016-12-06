#ifndef UNARYMODEL_HPP
#define UNARYMODEL_HPP
#include "operatormodel.hpp"
#include "blockcompositemodel.hpp"

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
			virtual std::string execute() = 0;
			virtual std::string getCategory() = 0;
			
		private:
			//operand 
			BlockCompositeModel* _operand;
	};
}

#endif	// BINARYMODEL_HPP
