#ifndef DIVMODEL_HPP
#define DIVMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/
namespace satap {

	class DivModel : public BinaryModel {

		public:
			DivModel();
			DivModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			DivModel(const BinaryModel & binaryModel);
			~DivModel();
			std::string execute();
	};
}

#endif	// DIVMODEL_HPP
