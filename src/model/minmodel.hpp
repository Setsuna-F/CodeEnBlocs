#ifndef MINMODEL_HPP
#define MINMODEL_HPP
#include "binarymodel.hpp"
#include "tools.h"
/*
 *
 * Description :
 *
 *
*/

namespace satap {
	
	class MinModel : public BinaryModel {
		
		public:
			MinModel();
			MinModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MinModel(const BinaryModel & binaryModel);
			~MinModel();
			sct_type execute();
			std::string getCategory();
	};
}

#endif	// MINMODEL_HPP
