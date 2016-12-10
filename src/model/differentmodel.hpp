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

	class DifferentModel : public BinaryModel {

		public:
			DifferentModel();
			DifferentModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			DifferentModel(const BinaryModel & binaryModel);
			~DifferentModel();
			sct_type execute();
	};
}

#endif	// DIFFERENTMODEL_HPP
