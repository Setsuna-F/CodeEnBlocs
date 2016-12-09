#ifndef INCMODEL_HPP
#define INCMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class IncModel : UnaryModel {

		public:
			IncModel();
			IncModel(BlockCompositeModel* operand);
			IncModel(const UnaryModel & unaryModel);
			~IncModel();
			sct_type execute();
	};
}

#endif	// INCMODEL_HPP
