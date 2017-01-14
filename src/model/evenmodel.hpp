#ifndef EVENMODEL_HPP
#define EVENMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class EvenModel : public UnaryModel {

		public:
			EvenModel();
			EvenModel(BlockCompositeModel* operand);
			EvenModel(const UnaryModel & unaryModel);
			~EvenModel();

			/*Methodes*/
			sct_type execute();
	};
}

#endif	// EVENMODEL_HPP
