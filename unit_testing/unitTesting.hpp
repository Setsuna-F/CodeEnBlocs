//
//  unitTesting.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 31/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef unitTesting_hpp
#define unitTesting_hpp

#include <stdio.h>

#include "inputlistmodel.hpp"

void testInputModel();
void testOutputModel();
void testVariableListModel();
void globalTests();

void testInputlistINT(satap::InputListModel &inputlist, int val_1, int val_2, int val_3);
void testInputlistDOUBLE(satap::InputListModel &inputlist, double val_1, double val_2, double val_3);
void testInputlistBOOL(satap::InputListModel &inputlist, bool val_1, bool val_2);

void testInputListModel();
void testOutputListModel();

void testIf();
void testLoop();

void unitTestingAdd();
void unitTestingSub();
void unitTestingMul();
void unitTestingDiv();
void unitTestingMod();

void unitTestingMax();
void unitTestingMin();

void unitTestingUpper();
void unitTestingPrime();

void unitTestingOr();
void unitTestingAnd();
void unitTestingNot();
void unitTestingAbs();
void unitTestingDec();
void unitTestingInc();
void unitTestingLess();
void unitTestingEqual();
void unitTestingLessThan();
void unitTestingDifferent();
void unitTestingGreaterThan();
void unitTestingLessThanOrEqual();
void unitTestingGreaterThanOrEqual();











/* ---------------------------- */
/**
 * \brief dans cette fonction nous allons voir un exemple d'exercice pouvant etre proposé.
 *
 *		Nom de l'exercice: RecupeInput
 *		explication:
 *			Cette fonction va prendre un input et va le mettre dans l'output
 *
 *		details:
 *			Premiere facon de faire:
 *				Faire un input et le mettre dans la variable
 *				utiliser la variable pour la mettre dans l'output.
 *
 *			(astuce): Autre facon de faire:
 *				Mettre directement dans l'output dans l'input.
 *
 */
void exempleExercice1();

#endif /* unitTesting_hpp */
