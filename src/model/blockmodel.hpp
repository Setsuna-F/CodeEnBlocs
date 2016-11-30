#ifndef BLOCKMODEL_HPP
#define BLOCKMODEL_HPP

#include <string>

namespace satap{

	class BlockModel {

		public:
			virtual std::string execute()=0;

	};

}

#endif
