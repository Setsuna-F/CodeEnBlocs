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

	class EqualModel : BinaryModel {

		public:
			EqualModel();
			EqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			EqualModel(const BinaryModel & binaryModel);
			~EqualModel();
			std::string execute();
	};
}

#endif	// EQUALMODEL_HPP
