#ifndef BLOCKSIMPLEMODEL_HPP
#define BLOCKSIMPLEMODEL_HPP

#include "blockmodel.hpp"
#include "tools.h"
/*
 *
 * Description : 
 *
 *
*/

namespace satap {

	class BlockSimpleModel : public BlockModel {
	
		public:
			//template<typename Type>
			virtual sct_type execute() = 0;
			virtual std::string getCategory() = 0;
	};
}

#endif	// BLOCKSIMPLEMODEL_HPP
