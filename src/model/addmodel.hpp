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
	class AddModel : public BinaryModel {
		public:
			AddModel();
			AddModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			AddModel(const BinaryModel & binaryModel);
			~AddModel();
			sct_type execute();

	};
}

#endif	// ADDMODEL_HPP
