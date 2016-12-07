#ifndef BLOCKCOMPOSITEMODEL_HPP
#define BLOCKCOMPOSITEMODEL_HPP

#include "blockmodel.hpp"
#include "tools.h"

namespace satap{

	class BlockCompositeModel : public BlockModel{
	
		public:
			virtual std::string getCategory() = 0;
			virtual sct_type execute()=0;
	
	};

}

#endif
