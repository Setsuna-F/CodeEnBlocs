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

	class GreaterThanOrEqualModel : public BinaryModel {

		public:
			GreaterThanOrEqualModel();
			GreaterThanOrEqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			GreaterThanOrEqualModel(const BinaryModel & binaryModel);
			~GreaterThanOrEqualModel();
			sct_type execute();
	};
}

#endif	// GREATERTHANOREQUALMODEL_HPP
