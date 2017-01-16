#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "additionlevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "addmodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
#include "valuemodel.hpp"
#include "assignmentmodel.hpp"

using namespace satap;

AdditionLevelModel::AdditionLevelModel() :
	LevelModel("Addition", 5, "On va te donner deux nombres, \nadditionne-les et donne le résultat calculé.", "Utilise un bloc d'addition après avoir récupéré \nles deux entrées dans deux variables."){ //TODO better help text
	reset();
}

void AdditionLevelModel::reset(){
	int min = 0;
	int max = 9;
	double output = 0;

	_workspace->flush();
	_codePage->flush();
	InputListModel* input = _workspace->getInputList();
	srand(time(NULL));

	for(int i=0; i<2; i++){
		int intdouble = 1 + (rand() % (int)(2 - 1 + 1));
		if(intdouble==1){
			sct_type foo;
			int bar;
			foo.double_type = nullptr;
			foo.bool_type = nullptr;
			bar = min + (rand() % (int)(max - min + 1));
			foo.int_type = new int(bar);
			output += *(foo.int_type);
			input->push(foo);
		}
		else{
			sct_type foo;
			double bar;
			double q;
			q = min + (rand() % (int)(100 - min + 1));
			bar = (double)(min + (rand() % (int)(max - min + 1))) + (double)(q/100);
			//bar = min + (rand() % (int)(max - min + 1));
			//bar = bar + (q/10);
			foo.double_type = new double(bar);
			foo.bool_type = nullptr;
			foo.int_type = nullptr;
			output += *(foo.double_type);
			input->push(foo);
		}
		//_workspace->setInputList(input);
	}
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(typeToString(output));
}
