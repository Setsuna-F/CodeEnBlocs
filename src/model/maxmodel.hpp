#ifndef MAXMODEL_HPP
#define MAXMODEL_HPP
#include "binarymodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/

namespace satap {
	
	class MaxModel : public BinaryModel {
		public:
			MaxModel();
			MaxModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MaxModel(const BinaryModel & binaryModel);
			~MaxModel();

			sct_type execute();
			std::string getCategory();
	};
}

#endif	// MAXMODEL_HPP
