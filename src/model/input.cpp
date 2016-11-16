//
//  input.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "input.hpp"
#include <iostream>
#include <string>

Input::Input(){}
Input::Input(std::stack<std::string> in): input(in){}

void		Input::push(std::string val){input.push(val);}
std::string Input::pop(){std::string val=input.top(); input.pop(); return val;}

bool	Input::isEmpty(){return input.empty();}
size_t	Input::size	  (){return input.size();}

