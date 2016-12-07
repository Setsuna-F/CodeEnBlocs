#ifndef PRIMEMODEL_HPP
#define PRIMEMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class PrimeModel : UnaryModel {

		public:
			PrimeModel();
			PrimeModel(BlockCompositeModel* operand);
			PrimeModel(const UnaryModel & unaryModel);
			~PrimeModel();
			std::string execute();
			
		private:
			bool isPrime(const int number, const int divider);
	};
}

#endif	// PRIMEMODEL_HPP
