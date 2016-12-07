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
			/*Constructeurs/Destructeur*/
			ModuloModel();
			ModuloModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
			ModuloModel(const BinaryModel & binaryModel);
			~ModuloModel();

			/*Methodes*/
			sct_type execute();

	};
}

#endif	// MODULOMODEL_HPP
