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
#include "valuemodel.hpp"
#include "assignmentmodel.hpp"

using namespace satap;

AdditionsLevelModel::AdditionsLevelModel() :
	LevelModel("Additions", 20, "On va te donner plusieurs nombres, \nadditionne-les tous et donne le résultat calculé.", "Additionne les deux premiers chiffres, puis additionne \nle résultat avec le chiffre suivant, et ainsi de suite."){ //TODO Find optimal block count
		// TODO a débugger
		/*
		_availableBlocks.setBlock(new AddModel(), "Addition");
		_availableBlocks.setBlock(new InputModel(), "Input");
		_availableBlocks.setBlock(new OutputModel(), "Output");
		_availableBlocks.setBlock(new VariableModel(), "Variable");
		_availableBlocks.setBlock(new ValueModel(),		"ValueModel");
		_availableBlocks.setBlock(new AssignmentModel(), "AssignmentModel");
		*/
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
