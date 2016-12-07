#ifndef MINMODEL_HPP
#define MINMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class MinModel : BinaryModel {

		public:
			MinModel();
			MinModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MinModel(const BinaryModel & binaryModel);
			~MinModel();
			std::string execute();
	};
}

#endif	// MINMODEL_HPP
