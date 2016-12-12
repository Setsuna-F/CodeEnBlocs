#ifndef MULTMODEL_HPP
#define MULTMODEL_HPP
#include "binarymodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/
namespace satap {

	class MultModel : public BinaryModel {

		public:
			/*Constructeurs/Destructeur*/
			MultModel();
			MultModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MultModel(const BinaryModel & binaryModel);
			~MultModel();
		
			/*Methodes*/
			sct_type execute();
	};
}

#endif	// MULTMODEL_HPP
