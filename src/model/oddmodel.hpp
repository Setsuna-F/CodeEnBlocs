#ifndef ODDMODEL_HPP
#define ODDMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class OddModel : public UnaryModel {

		public:
			OddModel();
			OddModel(BlockCompositeModel* operand);
			OddModel(const UnaryModel & unaryModel);
			~OddModel();

			/*Methodes*/
			sct_type execute();
	};
}

#endif	// ODDMODEL_HPP
