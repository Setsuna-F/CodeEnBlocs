//
//  inputlistmodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "inputlistmodel.hpp"
#include <iostream>
#include <string>

using namespace satap;

InputModel::InputListModel(){}
InputModel::InputListModel(std::stack<std::string> in){_input(in);}

void		InputListModel::push(std::string val){_input.push(val);}
std::string InputListModel::pop(){std::string val=_input.top(); _input.pop(); return val;} //TODO exception if empty

bool	InputListModel::isEmpty(){return _input.empty();}
size_t	InputListModel::size	  (){return _input.size();}

