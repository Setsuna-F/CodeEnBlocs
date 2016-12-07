#ifndef MODULOMODEL_HPP
#define MODULOMODEL_HPP
#include "binarymodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/
namespace satap {

	class ModuloModel : public BinaryModel {
	
		public:
			ModuloModel();
			ModuloModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			ModuloModel(const BinaryModel & binaryModel);
			~ModuloModel();
			sct_type execute();
			std::string getCategory();
	};
}

#endif	// MODULOMODEL_HPP
