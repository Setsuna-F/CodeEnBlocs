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
	LevelModel("Additions", 20, "On va te donner plusieurs nombres, additionne-les tous et donne le résultat calculé.", "Additionne les deux premiers chiffres, puis additionne le résultat avec le chiffre suivant, et ainsi de suite."){ //TODO Find optimal block count
	_availableBlocks.push_back(new AddModel());
	_availableBlocks.push_back(new InputModel());
	_availableBlocks.push_back(new OutputModel());
	_availableBlocks.push_back(new VariableModel());
	_availableBlocks.push_back(new ValueModel());
	_availableBlocks.push_back(new AssignmentModel());
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
