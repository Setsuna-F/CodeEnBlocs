#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "iolevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
//#include "affectationmodel.hpp"

using namespace satap;

IOLevelModel::IOLevelModel() :
	LevelModel("Entrée / Sortie", 2, "On va te donner un nombre, tu dois le restituer tel quel.", "Utilise le bloc Input pour lire une valeur en entrée et Output pour restituer une valeur en sortie."){
	_availableBlocks.push_back(new InputModel());
	_availableBlocks.push_back(new OutputModel());
	_availableBlocks.push_back(new VariableModel());
	//_availableBlocks.push_back(new Affectation()); //TODO
	reset();
}

void IOLevelModel::reset(){
	int min = 0;
	int max = 9;
	int output;

	_workspace->flush();
	_codePage->flush();
	InputListModel* input = _workspace->getInputList();
	srand(time(NULL));
	sct_type foo;
	int bar;
	foo.double_type = nullptr;
	foo.bool_type = nullptr;
	bar = min + (rand() % (int)(max - min + 1));
	foo.int_type = &bar;
	output = *(foo.int_type);
	input->push(foo);
	//_workspace->setInputList(input);
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(std::to_string(output));
}
