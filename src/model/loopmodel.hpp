#ifndef LOOPMODEL_HPP
#define LOOPMODEL_HPP
#include "blocksimplemodel.hpp"

/*
 *
 * Description : 
 *
 *
*/

namespace satap {

	class LoopModel : public BlockSimpleModel {
	
		public:
			LoopModel();
			~LoopModel();
			std::string execute();
	};
}

#endif	// LOOPMODEL_HPP
