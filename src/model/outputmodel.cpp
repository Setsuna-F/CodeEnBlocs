//
//  outputmodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "outputmodel.hpp"
#include <iostream>

using namespace satap;

OutputModel::OutputModel(){}

OutputModel::OutputModel(std::vector<std::string> out){_output = out;}

void OutputModel::push(std::string val){_output.push_back(val);}

void OutputModel::clear(){_output.clear();}

size_t OutputModel::size(){ return _output.size(); }

std::string OutputModel::getValByIndex(unsigned int i){ if(i<_output.size()) return _output[i]; else return NULL;} //TODO exception
