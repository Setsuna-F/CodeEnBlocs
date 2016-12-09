#ifndef GREATERTHANMODEL_HPP
#define GREATERTHANMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class GreaterThanModel : BinaryModel {

		public:
			GreaterThanModel();
			GreaterThanModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			GreaterThanModel(const BinaryModel & binaryModel);
			~GreaterThanModel();
			sct_type execute();
	};
}

#endif	// GREATERTHANMODEL_HPP
