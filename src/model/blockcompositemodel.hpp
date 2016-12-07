#ifndef BLOCKCOMPOSITEMODEL_HPP
#define BLOCKCOMPOSITEMODEL_HPP

#include "blockmodel.hpp"

namespace satap{

	class BlockCompositeModel : public BlockModel{

		public:
			virtual std::string execute()=0;

	};

}

#endif
