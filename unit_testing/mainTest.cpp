//
//  mainTest.cpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 06/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include <iostream>

#include "mainTest.hpp"

#include "ifmodel.hpp"
#include "variablemodel.hpp"
#include "maxmodel.hpp"
#include "uppermodel.hpp"

#include "variablelistmodel.hpp"
#include "loopmodel.hpp"
#include "tools.h"
#include "addmodel.hpp"

using namespace satap;

/*
 penser a faire des variables d'environement (variableList) pour verifiere que 2 variable n'ont pas le meme nom.
 */


void testIf(){
	/*std::cout <<"----------Test de if--------"<< std::endl;

	//Mes variables
	VariableModel var_m1("1", "42");
	VariableModel var_m2("2", "23");
	VariableModel var_m3("3", "666");
	VariableModel var_m4("4", "1");
	
	//Ma liste de variable (Mon env)
	VariableListModel varlist;
	varlist.setVariableModel(var_m1);
	varlist.setVariableModel(var_m2);
	varlist.setVariableModel(var_m3);
	varlist.setVariableModel(var_m4);
	varlist.setVariableModel(VariableModel("5", "1906"));
	
	//Ma condition
	MaxModel max_m(&var_m1, &var_m2);
	UpperModel upper_m(varlist.getVariableModel("1"), varlist.getVariableModel("3"));

	
	//Ma liste de condition
	std::vector<BlockCompositeModel *> conditionList;
	conditionList.push_back(&upper_m);
	
	//Mon bloc a executer si la condition est vrai
	std::vector<BlockModel *> blockListtrue;
	blockListtrue.push_back(&var_m3);
	blockListtrue.push_back(&var_m4);

	//Mon bloc a executer si la condition est fausse
	std::vector<BlockModel *> blockListfalse;
	blockListfalse.push_back(varlist.getVariableModel("5"));
	blockListfalse.push_back(varlist.getVariableModel("5"));
*/
	//Mon if
	/*
	 IfModel ifm(conditionList, blockListtrue, blockListfalse);
	std::cout<<"la valeur du if apres execution est: "<<ifm.execute()<<std::endl;
	std::cout<<"---"<<std::endl;

	
	std::cout<<"la taille du bloc true \t\tavant la suppresion est de "<<ifm.getBlockListTrue().size()<<std::endl;
	std::cout<<"la taille du bloc false \tavant la suppresion est de "<<ifm.getBlockListFalse().size()<<std::endl;
	std::cout<<"la taille du bloc condition avant la suppresion est de "<<ifm.getConditionList().size()<<std::endl;
	std::cout<<"---"<<std::endl;
	
	ifm.removeBlockTrue(1);
	std::cout<<"la taille du bloc true \t\tapres la suppresion est de "<<ifm.getBlockListTrue().size()<<std::endl;
	ifm.removeBlockFalse(0);
	std::cout<<"la taille du bloc false \tapres la suppresion est de "<<ifm.getBlockListFalse().size()<<std::endl;
	ifm.removeCondition(0);
	std::cout<<"la taille du bloc condition apres la suppresion est de "<<ifm.getConditionList().size()<<std::endl;
	*/
	
}


void testLoop(){
	std::cout <<"----------Test de loop--------"<< std::endl;
/*
	//Mes variables
	VariableModel var_m1("1", "42");
	VariableModel var_m2("2", "23");
	VariableModel var_m3("3", "666");
	VariableModel var_m4("4", "1");
	
	//Ma liste de variable
	VariableListModel varlist;
	varlist.setVariableModel(var_m1);
	varlist.setVariableModel(var_m2);
	varlist.setVariableModel(var_m3);
	varlist.setVariableModel(var_m4);
	varlist.setVariableModel(VariableModel("5", "1906"));
	
	//Ma condition
	MaxModel max_m(&var_m1, &var_m2);
	UpperModel upper_m(varlist.getVariableModel("1"), varlist.getVariableModel("2"));
	
	
	//Ma liste de condition
	std::vector<BlockCompositeModel *> conditionList;
	conditionList.push_back(&upper_m);
	
	//Mon bloc a executer si la condition est vrai
	std::vector<BlockModel *> blockList;
	blockList.push_back(&var_m3);
	blockList.push_back(&var_m4);
	
	//Mon if
	LoopModel loopm(conditionList, blockList);
	//std::cout<<"la valeur de la boucle est: "<<loopm.execute()<<std::endl;*/
}


void unitTestingAdd(){
	std::cout <<"----------Test de add--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = 23;
	double opd1 = 666.42;
	double opd2 = 42.666;
	bool opb1 = true;
	
	/*var 1*/
	var_type_value1.int_type	= &opi1;
	var_type_value1.double_type = nullptr;
	var_type_value1.bool_type	= nullptr;

	/*var 2*/
	var_type_value2.int_type	= &opi2;
	var_type_value2.double_type = nullptr;
	var_type_value2.bool_type	= nullptr;
	
	/*var 3*/
	var_type_value3.int_type	= nullptr;
	var_type_value3.double_type = &opd1;
	var_type_value3.bool_type	= nullptr;
	
	/*var 4*/
	var_type_value4.int_type	= nullptr;
	var_type_value4.double_type = &opd2;
	var_type_value4.bool_type	= nullptr;

	/*var 5*/
	var_type_value5.int_type	= nullptr;
	var_type_value5.double_type = nullptr;
	var_type_value5.bool_type	= &opb1;

	
	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("2", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	VariableModel var_m4("4", var_type_value4);
	VariableModel var_m5("5", var_type_value5);
	
	
	/*Nes classes d'addition*/
	AddModel add1(&var_m1, &var_m2);
	AddModel add2(&var_m3, &var_m4);
	AddModel add3(&var_m1, &var_m4);
	AddModel add4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666

	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (add "<<opi1<<" et "<<opi2<<") est : "<<*add1.execute().int_type<<std::endl;	// CAS int+int			: retourne 65
	std::cout<<"La valeur de l'addition (add "<<opd1<<" et "<<opd2<<") est : "<<*add2.execute().double_type<<std::endl; // CAS double+double	: retourne 709.086
	std::cout<<"La valeur de l'addition (add "<<opi1<<" et "<<opd2<<") est : "<<*add3.execute().double_type<<std::endl; // CAS int+double		: retourne 84.666
	
	if(!add4.execute().double_type)
		std::cout<<"La valeur de l'addition (add "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (add "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error

}



























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
	std::cout << "***********************************" << std::endl;
	std::cout << "**************| FIN |**************" << std::endl;
	std::cout << "***********************************" << std::endl;

	
	
	
	return 0;
}

