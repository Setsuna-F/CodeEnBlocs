//
//  inputmodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "inputmodel.hpp"
#include <iostream>
#include <string>

using namespace satap;

InputModel::InputModel(){}
InputModel::InputModel(std::stack<std::string> in){_input(in);}

void		InputModel::push(std::string val){_input.push(val);}
std::string InputModel::pop(){std::string val=_input.top(); _input.pop(); return val;}

bool	InputModel::isEmpty(){return _input.empty();}
size_t	InputModel::size	  (){return _input.size();}

