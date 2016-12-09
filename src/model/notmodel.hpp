#ifndef NOTMODEL_HPP
#define NOTMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class NotModel : UnaryModel {

		public:
			NotModel();
			NotModel(BlockCompositeModel* operand);
			NotModel(const UnaryModel & unaryModel);
			~NotModel();
			sct_type execute();
	};
}

#endif	// NOTMODEL_HPP
