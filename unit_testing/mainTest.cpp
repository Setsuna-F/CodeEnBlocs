//
//  mainTest.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 06/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include <iostream>

#include "mainTest.hpp"


#include "unitTesting.hpp"

/*
 penser a faire des variables d'environement (variableList) pour verifiere que 2 variable n'ont pas le meme nom.
 */



int main(int argc, char**argv){
	
	std::cout << "***********************************" << std::endl;
	std::cout << "**********| CodeEnBlocs |**********" << std::endl;
	std::cout << "************| MainTest |***********" << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
	
	testIf();
	std::cout << std::endl;
	testLoop();
	std::cout << std::endl;
	unitTestingAdd();
	std::cout << std::endl;
	unitTestingSub();
	std::cout << std::endl;
	unitTestingMul();
	std::cout << std::endl;
	unitTestingDiv();
	std::cout << std::endl;
	unitTestingMod();
	std::cout << std::endl;
	//unitTestingUpper();
	
	std::cout << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << "**************| FIN |**************" << std::endl;
	std::cout << "***********************************" << std::endl;

	
	
	
	return 0;
}

