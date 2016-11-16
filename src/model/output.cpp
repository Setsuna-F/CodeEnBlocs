//
//  output.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "output.hpp"
#include <iostream>

Output::Output(): output(){}

Output::Output(std::vector<std::string> out):output(out){}

void Output::push(std::string val){output.push_back(val);}

void Output::clear(){output.clear();}

size_t Output::size(){ return output.size(); }

std::string Output::getValByIndex(unsigned int i){ if(i<output.size()) return output[i]; else return NULL;}
