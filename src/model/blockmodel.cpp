//
//  blockmodel.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 11/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include <stdio.h>
#include "blockmodel.hpp"


namespace satap {
	
	BlockModel::BlockModel(): objSingleton(), id(0){
		objSingleton = UniqueObject::getInstance ();

		id = objSingleton->getValue();
		objSingleton->setValue (objSingleton->getValue()+1);
	}
	
	
	BlockModel* BlockModel::getBlockById(size_t id){
		//std::cout<<"r0 BLOMOD"<<std::endl;
		return nullptr;
	}
	
	BlockModel::~BlockModel(){
		objSingleton->kill ();
	}
	
	size_t BlockModel::getId(){ return id; }

}
