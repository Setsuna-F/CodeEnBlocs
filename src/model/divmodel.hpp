#ifndef DIVMODEL_HPP
#define DIVMODEL_HPP
#include "binarymodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/
namespace satap {

	class DivModel : public BinaryModel {

		public:
			DivModel();
			DivModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			DivModel(const BinaryModel & binaryModel);
			~DivModel();
			sct_type execute();

	};
}

#endif	// DIVMODEL_HPP
