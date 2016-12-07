#ifndef ADDMODEL_HPP
#define ADDMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class AddModel : BinaryModel {

		public:
			AddModel();
			AddModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			AddModel(const BinaryModel & binaryModel);
			~AddModel();
			std::string execute();
	};
}

#endif	// ADDMODEL_HPP
