#ifndef MAXMODEL_HPP
#define MAXMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class MaxModel : BinaryModel {

		public:
			MaxModel();
			MaxModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MaxModel(const BinaryModel & binaryModel);
			~MaxModel();
			std::string execute();
	};
}

#endif	// MAXMODEL_HPP
