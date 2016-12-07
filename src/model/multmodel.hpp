#ifndef MULTMODEL_HPP
#define MULTMODEL_HPP
#include "binarymodel.hpp"

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
			std::string execute();
	};
}

#endif	// MULTMODEL_HPP
