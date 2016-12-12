#ifndef BLOCKMODEL_HPP
#define BLOCKMODEL_HPP

#include <string>
#include <vector>
#include <iostream>

#include "tools.h"
#include "UniqueObject.hpp"


namespace satap{
	//class InstructionBlockModel;

	class BlockModel {
		public:
			BlockModel();
			~BlockModel();
			size_t getId();
			virtual sct_type execute() = 0;
			virtual BlockModel* getBlockById(size_t id)/* = 0*/;

		private:
			//std::vector<InstructionBlockModel *> blocks;
			UniqueObject *objSingleton; /* Notre objet singleton qui s'icrementra a chaque construction de bloc */
			size_t id;
	};

}




#endif
