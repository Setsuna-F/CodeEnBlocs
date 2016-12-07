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

	class DecModel : UnaryModel {

		public:
			DecModel();
			DecModel(BlockCompositeModel* operand);
			DecModel(const UnaryModel & unaryModel);
			~DecModel();
			std::string execute();
	};
}

#endif	// DECMODEL_HPP
