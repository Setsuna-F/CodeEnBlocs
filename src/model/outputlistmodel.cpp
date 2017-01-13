//
//  outputmodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "outputlistmodel.hpp"
#include <iostream>

using namespace satap;

OutputListModel::OutputListModel(){}

OutputListModel::OutputListModel(std::vector<std::string> out){_output = out;}

void OutputListModel::push(std::string val){_output.push_back(val);}

void OutputListModel::clear(){_output.clear();}

size_t OutputListModel::size(){ return _output.size(); }

std::string satap::OutputListModel::toString()
{
	std::string s = "";
	for (auto &o : _output) {
		s += o + "\n";
	}
	return s;
}

std::vector<std::string> OutputListModel::getOutputList(){ return _output; }

std::string OutputListModel::getValByIndex(unsigned int i){ if(i<_output.size()) return _output[i]; else return NULL;} //TODO exception
