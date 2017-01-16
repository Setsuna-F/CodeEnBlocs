#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "sublevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "submodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
#include "valuemodel.hpp"
#include "assignmentmodel.hpp"

using namespace satap;

SubLevelModel::SubLevelModel() :

	LevelModel("Soustraction", 10, "On va te donner deux nombres, \nsoustrais-les et donne le résultat calculé.", "Utilise un bloc de soustraction après avoir récupéré \nles deux entrées dans deux variables."){ //TODO better help text
	// TODO A débuguer
	/*_availableBlocks.setBlock(new AddModel(), "Addition");
	_availableBlocks.setBlock(new InputModel(), "Input");
	_availableBlocks.setBlock(new OutputModel(), "Output");
	_availableBlocks.setBlock(new VariableModel(), "Variable");
	_availableBlocks.setBlock(new ValueModel(),		"ValueModel");
	_availableBlocks.setBlock(new AssignmentModel(), "AssignmentModel");*/

	reset();
}

void SubLevelModel::reset(){
	int min = 0;
	int max = 9;
	int output = 0;

	_workspace->flush();
	_codePage->flush();
	InputListModel* input = _workspace->getInputList();
	srand(time(NULL));

	for(int i=0; i<2; i++){
		sct_type foo;
		int bar;
		foo.double_type = nullptr;
		foo.bool_type = nullptr;
		bar = min + (rand() % (int)(max - min + 1));
		foo.int_type = new int(bar);
		output += *(foo.int_type);
		input->push(foo);
		//_workspace->setInputList(input);
	}
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(std::to_string(output));
}
