#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "additionlevelmodel.hpp"
#include "inputlistmodel.hpp"

using namespace satap;

AdditionLevelModel::AdditionLevelModel() :
	LevelModel("Addition", "On va te donner deux nombres, additionne-les et donne le résultat calculé"){
	init();
}

void AdditionLevelModel::init(){
	int min = 0;
	int max = 10;
	int output = 0;
	InputListModel input;
	
	_workspace.flush();
	srand(time(NULL));
	
	
	for(int i=0; i<2; i++){
		sct_type foo;
		int bar;
		foo.double_type = nullptr;
		foo.double_type = nullptr;
		foo.bool_type = nullptr;
		bar = min + (rand() % (int)(max - min + 1));
		foo.int_type = &bar;
		output += *(foo.int_type);
		input.push(foo);
	}
	_workspace.setInputList(input);
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(std::to_string(output));
}
