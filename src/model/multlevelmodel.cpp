#include <stdlib.h>
#include <time.h>
#include <string>
#include "../tools.h"

#include "multlevelmodel.hpp"
#include "inputlistmodel.hpp"
#include "multmodel.hpp"
#include "inputmodel.hpp"
#include "outputmodel.hpp"
#include "variablemodel.hpp"
#include "valuemodel.hpp"
#include "assignmentmodel.hpp"

using namespace satap;

MultLevelModel::MultLevelModel() :

	LevelModel("Multiplication", 10, "On va te donner deux nombres, \nmultiplie-les et donne le résultat calculé.", "Utilise un bloc de multiplication après avoir récupéré \nles deux entrées dans deux variables."){ //TODO better help text

	reset();
}

void MultLevelModel::reset(){
	int min = 0;
	int max = 9;
	int output = 0;
    int output1 = 0;
    int output2 = 0;

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
            output1 = *(foo.int_type);
            input->push(foo);
        }
        else{
            sct_type foo;
            double bar;
            int q;
            int d;
            q = min + (rand() % (int)(max - min + 1));
            d = min + (rand() % (int)(max - min + 1)) + 1;
            bar = (double)(min + (rand() % (int)(max - min + 1))) + (double)(q/d);
            foo.double_type = new double(bar);
            foo.bool_type = nullptr;
            foo.int_type = nullptr;
            output2 = *(foo.double_type);
            input->push(foo);
        }
    }
    output = output1*output2;
	_outputListExpected = *(new OutputListModel());
	_outputListExpected.push(typeToString(output));
}
