#ifndef SUBMODEL_HPP
#define SUBMODEL_HPP
#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/
namespace satap {

	class SubModel : public BinaryModel {
	
		public:
			SubModel();
			SubModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			SubModel(const BinaryModel & binaryModel);
			~SubModel();
			sct_type execute();
			std::string getCategory();
	};
}

#endif	// SUBMODEL_HPP
