#ifndef BLOCKMODEL_HPP
#define BLOCKMODEL_HPP

#include <string>
#include <vector>
#include <iostream>

#include "tools.h"
#include "UniqueObject.hpp"

namespace satap{
	
	class WorkspaceModel;
	
	class BlockModel {
		public:
			BlockModel();
			BlockModel(WorkspaceModel &workspace);
			~BlockModel();
			size_t getId();
			virtual sct_type execute() = 0;
			virtual BlockModel* getBlockById(size_t id)/* = 0*/;
			void setWorspace(WorkspaceModel &workspace);
		private:
			UniqueObject *objSingleton; /* Notre objet singleton qui s'icrementra a chaque construction de bloc */
			WorkspaceModel* _workspace;
			size_t _id;
	};

}




#endif
