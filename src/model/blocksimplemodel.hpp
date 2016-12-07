#ifndef BLOCKSIMPLEMODEL_HPP
#define BLOCKSIMPLEMODEL_HPP
#include "blockmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class BlockSimpleModel : public BlockModel {

		public:
			virtual std::string execute() = 0;
	};
}

#endif	// BLOCKSIMPLEMODEL_HPP
