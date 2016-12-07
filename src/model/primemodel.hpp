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
	
	class PrimeModel : public UnaryModel {
		public:
			/*Consctructeurs/Destructeur*/
			PrimeModel();
			PrimeModel(BlockCompositeModel* operand);
			PrimeModel(const UnaryModel & unaryModel);
			~PrimeModel();

			/**/
			sct_type execute();

			
		private:
			bool isPrime(const int number, const int divider);
	};
}

#endif	// PRIMEMODEL_HPP
