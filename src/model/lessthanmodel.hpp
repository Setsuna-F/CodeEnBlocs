#ifndef LESSTHANMODEL_HPP
#define LESSTHANMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class LessThanModel : public BinaryModel {

		public:
			LessThanModel();
			LessThanModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			LessThanModel(const BinaryModel & binaryModel);
			~LessThanModel();
			sct_type execute();
	};
}

#endif	// LESSTHANMODEL_HPP
