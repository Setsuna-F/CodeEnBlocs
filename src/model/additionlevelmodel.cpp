#include <stdlib.h>
#include <time.h>
#include <string>

#include "additionlevelmodel.hpp"
#include "inputlistmodel.hpp"

using namespace satap;

AdditionLevelModel::AdditionLevelModel() :
	LevelModel("Addition"){
	init();
}

void AdditionLevelModel::init(){
	int min = 0;
	int max = 10;
	int foo;
	int output = 0;
	InputListModel input;
	
	_workspace.flush();
	srand(time(NULL));
	
	for(int i=0; i<2; i++){
		foo = min + (rand() % (int)(max - min + 1));
		output += foo;
		input.push(std::to_string(foo));
	}
	_workspace.setInputList(input);
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(std::to_string(output));
}
