#ifndef ANDMODEL_HPP
#define ANDMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class AndModel : public BinaryModel {

		public:
			AndModel();
			AndModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			AndModel(const BinaryModel & binaryModel);
			~AndModel();
		
			/*Methodes*/
			sct_type execute();
	};
}

#endif	// ANDMODEL_HPP
