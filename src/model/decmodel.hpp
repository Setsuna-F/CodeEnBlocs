#ifndef DECMODEL_HPP
#define DECMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class DecModel : public UnaryModel {

		public:
			DecModel();
			DecModel(BlockCompositeModel* operand);
			DecModel(const UnaryModel & unaryModel);
			~DecModel();
			sct_type execute();
	};
}

#endif	// DECMODEL_HPP
