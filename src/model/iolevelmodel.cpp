#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "iolevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
#include "valuemodel.hpp"
#include "assignmentmodel.hpp"

using namespace satap;

IOLevelModel::IOLevelModel() :
	LevelModel("Entrée / Sortie", 3, "On va te donner un nombre, tu dois le restituer tel quel.", "Utilise le bloc Input pour lire une valeur en entrée \n et Output pour restituer une valeur en sortie."){

		// TODO a débugger
		/*
		_availableBlocks.setBlock(new InputModel(), "Input");
		_availableBlocks.setBlock(new OutputModel(), "Output");
		_availableBlocks.setBlock(new VariableModel(), "Variable");
		_availableBlocks.setBlock(new ValueModel(),		"ValueModel");
		_availableBlocks.setBlock(new AssignmentModel(), "AssignmentModel");*/
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
	foo.int_type = new int(bar);
	output = *(foo.int_type);
	input->push(foo);
	//_workspace->setInputList(input);
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(std::to_string(output));
}
