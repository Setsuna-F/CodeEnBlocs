#ifndef BLOCKMODEL_HPP
#define BLOCKMODEL_HPP

#include <string>
#include <vector>
#include <iostream>

#include "tools.h"

namespace satap{

	class BlockModel {

		public:
			virtual sct_type execute() = 0;
	};

}

#endif
