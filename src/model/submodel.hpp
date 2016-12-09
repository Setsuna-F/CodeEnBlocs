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
			/*Constructeurs/Destructeur*/
			SubModel();
			SubModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			SubModel(const BinaryModel & binaryModel);
			~SubModel();

			/*Methodes*/
			sct_type execute();

	};
}

#endif	// SUBMODEL_HPP
