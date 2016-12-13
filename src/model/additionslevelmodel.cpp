#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "additionslevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "addmodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
//#include "affectationmodel.hpp"

using namespace satap;

AdditionsLevelModel::AdditionsLevelModel() :
	LevelModel("Additions", 10, "On va te donner deux nombres, additionne-les et donne le résultat calculé.", "Utilise un bloc d'addition après avoir récupéré les deux entrées dans deux variables."){ //TODO better help text
	_availableBlocks.push_back(new AddModel());
	_availableBlocks.push_back(new InputModel());
	_availableBlocks.push_back(new OutputModel());
	_availableBlocks.push_back(new VariableModel());
	//_availableBlocks.push_back(new Affectation()); //TODO
	reset();
}

void AdditionsLevelModel::reset(){
	int min = 0;
	int max = 9;
	int output = 0;

	_workspace->flush();
	_codePage->flush();
	InputListModel* input = _workspace->getInputList();
	srand(time(NULL));

	for(int i=0; i<5; i++){
		sct_type foo;
		int bar;
		foo.double_type = nullptr;
		foo.bool_type = nullptr;
		bar = min + (rand() % (int)(max - min + 1));
		foo.int_type = &bar;
		output += *(foo.int_type);
		input->push(foo);
		//_workspace->setInputList(input);
	}
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(std::to_string(output));
}
