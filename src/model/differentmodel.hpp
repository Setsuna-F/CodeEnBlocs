#ifndef DIFFERENTMODEL_HPP
#define DIFFERENTMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class DifferentModel : BinaryModel {

		public:
			DifferentModel();
			DifferentModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			DifferentModel(const BinaryModel & binaryModel);
			~DifferentModel();
			std::string execute();
	};
}

#endif	// DIFFERENTMODEL_HPP
