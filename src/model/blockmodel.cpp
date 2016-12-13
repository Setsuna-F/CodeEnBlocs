//
//  blockmodel.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 11/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include <stdio.h>
#include "blockmodel.hpp"
#include "Workspacemodel.hpp"


namespace satap {
	
	BlockModel::BlockModel():
		objSingleton(),
		_id(0){
		objSingleton	= UniqueObject::getInstance ();
		_id				= objSingleton->getValue();
		objSingleton->setValue (objSingleton->getValue()+1);
	}
	
	BlockModel::BlockModel(WorkspaceModel &workspace):
		_workspace(&workspace),
		objSingleton(),
		_id(0){
		objSingleton	= UniqueObject::getInstance ();
		_id				= objSingleton->getValue();
		objSingleton->setValue (objSingleton->getValue()+1);
	}
	
	void BlockModel::setWorspace(WorkspaceModel &workspace){
		_workspace=&workspace;
	}

	BlockModel* BlockModel::getBlockById(size_t id){
		return nullptr;
	}

	BlockModel::~BlockModel(){
		objSingleton->kill ();
	}
	
	size_t BlockModel::getId(){ return _id; }

}



