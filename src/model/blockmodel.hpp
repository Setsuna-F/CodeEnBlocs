#ifndef BLOCKMODEL_HPP
#define BLOCKMODEL_HPP

#include <string>
#include <vector>
#include <iostream>

namespace satap{

	class BlockModel {

		public:
			virtual std::string execute()=0;

	};

}

#endif
