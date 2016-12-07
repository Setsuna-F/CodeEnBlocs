#ifndef GREATERTHANOREQUALMODEL_HPP
#define GREATERTHANOREQUALMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class GreaterThanOrEqualModel : BinaryModel {

		public:
			GreaterThanOrEqualModel();
			GreaterThanOrEqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			GreaterThanOrEqualModel(const BinaryModel & binaryModel);
			~GreaterThanOrEqualModel();
			std::string execute();
	};
}

#endif	// GREATERTHANOREQUALMODEL_HPP
