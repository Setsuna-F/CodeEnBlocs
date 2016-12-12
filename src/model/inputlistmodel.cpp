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

InputListModel::InputListModel(){}
InputListModel::InputListModel(std::stack<sct_type> in):_input(in) {}

void		InputListModel::push(sct_type val){_input.push(val);}
sct_type	InputListModel::pop(){sct_type res = _input.top(); _input.pop(); return res;} //TODO exception if empty

bool	InputListModel::isEmpty(){return _input.empty();}
size_t	InputListModel::size	  (){return _input.size();}

