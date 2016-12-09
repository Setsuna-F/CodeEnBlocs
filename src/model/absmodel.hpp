#ifndef ABSMODEL_HPP
#define ABSMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class AbsModel : UnaryModel {

		public:
			AbsModel();
			AbsModel(BlockCompositeModel* operand);
			AbsModel(const UnaryModel & unaryModel);
			~AbsModel();
			sct_type execute();
	};
}

#endif	// ABSMODEL_HPP
