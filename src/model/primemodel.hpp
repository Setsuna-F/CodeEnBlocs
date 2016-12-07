#ifndef PRIMEMODEL_HPP
#define PRIMEMODEL_HPP
#include "binarymodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/

namespace satap {
	
	class PrimeModel : public BinaryModel {
		
		public:
			PrimeModel();
			PrimeModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			PrimeModel(const BinaryModel & binaryModel);
			~PrimeModel();
			sct_type execute();
			std::string getCategory();
	};
}

#endif	// PRIMEMODEL_HPP
