#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "divlevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "divmodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
#include "valuemodel.hpp"
#include "assignmentmodel.hpp"

using namespace satap;

DivLevelModel::DivLevelModel() :

	LevelModel("Division", 10, "On va te donner deux nombres, \ndivise-les et donne le résultat calculé.", "Utilise un bloc de division."){ //TODO better help text
	reset();
}

void DivLevelModel::reset(){
	int min = 0;
	int max = 9;
	double output = 0;

	_workspace->flush();
	_codePage->flush();
	InputListModel* input = _workspace->getInputList();
	srand(time(NULL));

	sct_type foo;
	int bar;
	foo.double_type = nullptr;
	foo.bool_type = nullptr;
	bar = min + (rand() % (int)(max - min + 1))+1;
	foo.int_type = new int(bar);
	output += *(foo.int_type);
	input->push(foo);
	//_workspace->setInputList(input);

	foo.double_type = nullptr;
	foo.bool_type = nullptr;
	bar = min + (rand() % (int)(max - min + 1));
	foo.int_type = new int(bar);
	output += *(foo.int_type);
	input->push(foo);
	//_workspace->setInputList(input);



	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(typeToString(output));
}
