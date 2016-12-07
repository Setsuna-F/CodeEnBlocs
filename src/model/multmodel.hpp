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
			MultModel();
			MultModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			MultModel(const BinaryModel & binaryModel);
			~MultModel();
			sct_type execute();
			std::string getCategory();
	};
}

#endif	// MULTMODEL_HPP
