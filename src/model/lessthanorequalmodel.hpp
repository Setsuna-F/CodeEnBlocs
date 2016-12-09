#ifndef LESSTHANOREQUALMODEL_HPP
#define LESSTHANOREQUALMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class LessThanOrEqualModel : BinaryModel {

		public:
			LessThanOrEqualModel();
			LessThanOrEqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			LessThanOrEqualModel(const BinaryModel & binaryModel);
			~LessThanOrEqualModel();
			sct_type execute();
	};
}

#endif	// LESSTHANOREQUALMODEL_HPP
