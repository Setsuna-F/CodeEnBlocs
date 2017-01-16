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

	reset();
}

void SubLevelModel::reset(){
	int min = 0;
	int max = 50;
    double output = 0;
    double output1 = 0;
    double output2 = 0;
	bool op=false;

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
			if(op) output1 = bar;
			else{
				output2 = bar;
				op=true;
			}
		    input->push(foo);
        }
        else{
			sct_type foo;
			double bar;
			double q;
			q = min + (rand() % (int)(100 - min + 1));
			bar = (double)(min + (rand() % (int)(max - min + 1))) + (double)(q/100);
			foo.double_type = new double(bar);
            foo.bool_type = nullptr;
            foo.int_type = nullptr;
			if(op) output1 = bar;
			else{
				output2 = bar;
				op=true;
			}
			input->push(foo);
        }
    }
    output = output2-output1;
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(typeToString(output));
}
