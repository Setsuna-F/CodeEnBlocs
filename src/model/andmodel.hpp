#ifndef ANDMODEL_HPP
#define ANDMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class AndModel : BinaryModel {

		public:
			AndModel();
			AndModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			AndModel(const BinaryModel & binaryModel);
			~AndModel();
			std::string execute();
	};
}

#endif	// ANDMODEL_HPP
