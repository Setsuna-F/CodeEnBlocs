#ifndef EQUALMODEL_HPP
#define EQUALMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class EqualModel : public BinaryModel {

		public:
			EqualModel();
			EqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			EqualModel(const BinaryModel & binaryModel);
			~EqualModel();
			sct_type execute();
	};
}

#endif	// EQUALMODEL_HPP
