#ifndef ORMODEL_HPP
#define ORMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class OrModel : BinaryModel {

		public:
			OrModel();
			OrModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			OrModel(const BinaryModel & binaryModel);
			~OrModel();
			std::string execute();
	};
}

#endif	// ORMODEL_HPP
