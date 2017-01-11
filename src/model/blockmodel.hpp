#ifndef BLOCKMODEL_HPP
#define BLOCKMODEL_HPP

#include <string>
#include <vector>
#include <iostream>

#include "tools.h"
#include "UniqueObject.hpp"

namespace satap{

	enum typeBloc {
		BlocType,
		VariableBlocType,
		InputBlocType,
		OutputBlocType,
		AssignementBlocType,
		AddBlocType,
		SubBlocType,
		MultBlocType,
		DivBlocType,
		MaxBlocType,
		MinBlocType,
		NotBlocType,
		EqualBlocType,
		IfBlocType,
		ForBlocType,
		WhileBlocType,
		FonctionBlocType,
		ND
	};

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
			/*virtual*/ typeBloc getType(){
				//std::cout << "GETTYPE !!!! "<<std::endl;
				return _type;
			}
			/*virtual*/ void setType(typeBloc t){_type=t;}
			/*virtual */int getNbElements();
		protected:
			UniqueObject *objSingleton; /* Notre objet singleton qui s'icrementra a chaque construction de bloc */
			WorkspaceModel* _workspace;
			size_t _id;
			satap::typeBloc _type = ND;
	};

}




#endif
