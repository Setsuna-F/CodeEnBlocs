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
			/*Constructeurs/Destructeur*/
			MinModel();
			MinModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MinModel(const BinaryModel & binaryModel);
			~MinModel();
		
			/*Methodes*/
			sct_type execute();
	};
}

#endif	// MINMODEL_HPP
