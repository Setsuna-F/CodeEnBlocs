#ifndef PRIMEMODEL_HPP
#define PRIMEMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {
	
	class PrimeModel : BinaryModel {
		
		public:
			PrimeModel();
			PrimeModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			PrimeModel(const BinaryModel & binaryModel);
			~PrimeModel();
			std::string execute();
			std::string getCategory();
	};
}

#endif	// PRIMEMODEL_HPP
