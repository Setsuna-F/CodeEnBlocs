//
//  unitTesting.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 31/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include <iostream>
#include <assert.h>

#include "unitTesting.hpp"

#include "../src/model/inputlistmodel.hpp"
#include "../src/model/outputlistmodel.hpp"
#include "../src/model/variablelistmodel.hpp"






#include "ifmodel.hpp"

#include "variablelistmodel.hpp"
#include "loopmodel.hpp"

#include "tools.h"

#include "addmodel.hpp"
#include "submodel.hpp"
#include "multmodel.hpp"
#include "divmodel.hpp"
#include "modulomodel.hpp"

#include "variablemodel.hpp"
#include "maxmodel.hpp"
#include "minmodel.hpp"
#include "uppermodel.hpp"
#include "primemodel.hpp"



using namespace satap;



void globalTests(){
	std::cout<<"////////////////////////"<<std::endl;
	std::cout<<"///unit testing begin///"<<std::endl;
	std::cout<<"////////////////////////"<<std::endl;
	
	std::cout<<"   | INPUTLISTMODEL |   "<<std::endl;
	//testInputModel();
	
	std::cout<<"   | OUTPUTLISTMODEL |   "<<std::endl;
	//testOutputModel();
	
	std::cout<<"   | VARIABLELISTMODEL |   "<<std::endl;
	//testVariableListModel();
	
	std::cout<<"//////////////////////"<<std::endl;
	std::cout<<"///unit testing end///"<<std::endl;
	std::cout<<"//////////////////////"<<std::endl;
}



void testVariableListModel(){
	/*std::cout<<"Test de VariableListModel: "<<std::endl;

	satap::VariableListModel vl;
	vl.setVariable("soka", "stella");
	vl.setVariable("soso", "steste");
	vl.setVariable("solaris");
	vl.setVariable("jake", "jojo");
	std::cout<<"Size of variableList is : "<<vl.size()<<std::endl;

	std::string val1 = vl.getValue("soka");
	if(val1 != "stella")	std::cout<<"Test has FAILED: "	<<val1<<"!=stella"<<std::endl;
	else					std::cout<<"Test SUCCESS: "		<<val1<<"==stella"<<std::endl;
	
	std::string val2 = vl.getValue("jake");
	if(val2 != "jojo")	std::cout<<"Test has FAILED: "		<<val2<<"!=jojo"<<std::endl;
	else				std::cout<<"Test SUCCESS: "			<<val2<<"==jojo"<<std::endl;
	
	std::string val3 = vl.getValue("stylo");
	if(!val3.empty())	std::cout<<"Test has FAILED: "		<<val3<<"!=NULL"<<std::endl;
	else				std::cout<<"Test SUCCESS: is empty" <<std::endl;

	vl.removeValue("jake");
	std::string val4 = vl.getValue("jake");
	if(!val4.empty())	std::cout<<"Test has FAILED: "		<<val4<<"!=NULL"<<std::endl;
	else				std::cout<<"Test SUCCESS: is empty" <<std::endl;

	std::cout<<"Size of variableList is : "<<vl.size()<<std::endl;*/
}


void testOutputListModel(){
	std::cout<<"Test de OutputModel: "<<std::endl;
	std::cout<<"Test du contructeur avec param: "<<std::endl;

	std::vector<std::string> v;
	v.push_back("stella");
	v.push_back("stello");
	v.push_back("stelli");
	satap::OutputListModel outv(v);
	outv.clear();
	std::cout<<"Test du contructeur sans param: "<<std::endl;
	satap::OutputListModel out;
	out.push("soka");
	out.push("soda");
	out.clear();
}


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




void testInputListModel(){
 	///////////Test unitaire des input.
	///////////Constructeur avec parametre:
	std::cout<<"Test de InputModel: "				 <<std::endl;
	std::cout<<"Test du contructeur avec param: "<<std::endl;
	std::stack<std::string> vs;
	vs.push("stella");
	vs.push("stello");
	vs.push("stelli");
	/*satap::InputListModel invs(vs);
	if(invs.size()!=3)	std::cout<<"Test has FAILED: "	<<invs.size()<<"!=3"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<invs.size()<<"==3"<<std::endl;
	*//*---------------------------*/

	/*std::string v1 = invs.pop();
	if(v1!="stelli")	std::cout<<"Test has FAILED: "	<<v1<<"!=stelli"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<v1<<"==stelli"<<std::endl;
	if(invs.size()!=2)	std::cout<<"Test has FAILED: "	<<invs.size()<<"!=2"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<invs.size()<<"==2"<<std::endl;
	*//*---------------------------*/

	
	/*std::string v2 = invs.pop();
	if(v2!="stello")	std::cout<<"Test has FAILED: "	<<v2		 <<"!=stello"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<v2		 <<"==stello"<<std::endl;
	if(invs.size()!=1)	std::cout<<"Test has FAILED: "	<<invs.size()<<"!=1"	 <<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<invs.size()<<"==1"	 <<std::endl;
	*//*---------------------------*/
	
	///////////Constructeur sans parametre:
	std::cout<<"Test du contructeur sans param: "<<std::endl;
	/*Input in;
	in.push("soka");
	in.push("soja");
	in.push("soya");
	in.push("jojo");
	in.push("soda");
	if(in.size()!=5) std::cout<<"Test has FAILED: "	<<in.size()<<"!=5"<<std::endl;
	else			 std::cout<<"Test SUCCESS: "	<<in.size()<<"==5"<<std::endl;*/
	/*---------------------------*/

	/*std::string v3 = in.pop();
	if(v3!="soda")	std::cout<<"Test has FAILED: "	<<v3		<<"!=soda"<<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<v3		<<"==soda"<<std::endl;
	if(in.size()!=4)std::cout<<"Test has FAILED: "	<<in.size() <<"!=4"	  <<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<in.size() <<"==4"	  <<std::endl;*/
	/*---------------------------*/
	
	/*std::string v4 = in.pop();
	if(v4!="jojo")	std::cout<<"Test has FAILED: "	<<v4		<<"!=jojo"<<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<v4		<<"==jojo"<<std::endl;
	if(in.size()!=3)std::cout<<"Test has FAILED: "	<<in.size() <<"!=3"	  <<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<in.size() <<"==3"	  <<std::endl;*/
	/*---------------------------*/
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

void unitTestingSub(){
	std::cout <<"----------Test de sub--------"<< std::endl;
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
	SubModel sub1(&var_m1, &var_m2);
	SubModel sub2(&var_m3, &var_m4);
	SubModel sub3(&var_m1, &var_m4);
	SubModel sub4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (add "<<opi1<<" et "<<opi2<<") est : "<<*sub1.execute().int_type<<std::endl;	// CAS int+int			: retourne 65
	std::cout<<"La valeur de l'addition (add "<<opd1<<" et "<<opd2<<") est : "<<*sub2.execute().double_type<<std::endl; // CAS double+double	: retourne 709.086
	std::cout<<"La valeur de l'addition (add "<<opi1<<" et "<<opd2<<") est : "<<*sub3.execute().double_type<<std::endl; // CAS int+double		: retourne 84.666
	
	if(!sub4.execute().double_type)
		std::cout<<"La valeur de l'addition (sub "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (sub "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingMul(){
	std::cout <<"----------Test de mult--------"<< std::endl;
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
	MultModel mult1(&var_m1, &var_m2);
	MultModel mult2(&var_m3, &var_m4);
	MultModel mult3(&var_m1, &var_m4);
	MultModel mult4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<opi2<<") est : "<<*mult1.execute().int_type<<std::endl;	// CAS int+int			: retourne 966
	std::cout<<"La valeur de l'addition (mult "<<opd1<<" et "<<opd2<<") est : "<<*mult2.execute().double_type<<std::endl; // CAS double+double	: retourne 28433.47572
	std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<opd2<<") est : "<<*mult3.execute().double_type<<std::endl; // CAS int+double		: retourne 1791.972
	
	if(!mult4.execute().double_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingDiv(){
	std::cout <<"----------Test de div--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	sct_type var_type_value6;

	int opi1 = 42;
	int opi2 = 23;
	int opi3 = 0;
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

	/*var 6*/
	var_type_value6.int_type	= &opi3;
	var_type_value6.double_type = nullptr;
	var_type_value6.bool_type	= nullptr;


	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("2", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	VariableModel var_m4("4", var_type_value4);
	VariableModel var_m5("5", var_type_value5);
	VariableModel var_m6("5", var_type_value6);


	/*Nes classes d'addition*/
	DivModel div1(&var_m1, &var_m2);
	DivModel div2(&var_m3, &var_m4);
	DivModel div3(&var_m1, &var_m4);
	DivModel div4(&var_m1, &var_m5);
	DivModel div5(&var_m1, &var_m6);

	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (div "<<opi1<<" et "<<opi2<<") est : "<<*div1.execute().int_type<<std::endl;	// CAS int+int			: retourne 1
	std::cout<<"La valeur de l'addition (div "<<opd1<<" et "<<opd2<<") est : "<<*div2.execute().double_type<<std::endl; // CAS double+double	: retourne 15.60961890
	std::cout<<"La valeur de l'addition (div "<<opi1<<" et "<<opd2<<") est : "<<*div3.execute().double_type<<std::endl; // CAS int+double		: retourne 0.984390381
	
	if(!div4.execute().double_type)
		std::cout<<"La valeur de l'addition (div "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (div "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
	
	
	if(!div5.execute().int_type)
		std::cout<<"La valeur de l'addition (div "<<opi1<<" et "<<(opi3?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (div "<<opi1<<" et "<<(opi3?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingMod(){
	std::cout <<"----------Test de mod--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	sct_type var_type_value6;
	
	int opi1 = 42;
	int opi2 = 23;
	int opi3 = 0;
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
	
	/*var 6*/
	var_type_value6.int_type	= &opi3;
	var_type_value6.double_type = nullptr;
	var_type_value6.bool_type	= nullptr;
	
	
	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("2", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	VariableModel var_m4("4", var_type_value4);
	VariableModel var_m5("5", var_type_value5);
	VariableModel var_m6("5", var_type_value6);
	
	
	/*Nes classes d'addition*/
	ModuloModel mod1(&var_m1, &var_m2);
	ModuloModel mod2(&var_m3, &var_m4);
	ModuloModel mod3(&var_m1, &var_m4);
	ModuloModel mod4(&var_m1, &var_m5);
	ModuloModel mod5(&var_m1, &var_m6);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (mod "<<opi1<<" et "<<opi2<<") est : "<<*mod1.execute().int_type<<std::endl;	// CAS int+int			: retourne 19
	
	if(!mod4.execute().double_type)
		std::cout<<"La valeur de l'addition (mod "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mod "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
	
	
	if(!mod5.execute().int_type)
		std::cout<<"La valeur de l'addition (mod "<<opi1<<" et "<<opi3<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mod "<<opi1<<" et "<<opi3<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
	
	
	if(!mod2.execute().double_type)
		std::cout<<"La valeur de l'addition (mod "<<opd1<<" et "<<opd2<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mod "<<opd1<<" et "<<opd2<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingUpper(){
	std::cout <<"----------Test de upper--------"<< std::endl;
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
	UpperModel upper1(&var_m1, &var_m2);
	UpperModel upper2(&var_m3, &var_m4);
	UpperModel upper3(&var_m1, &var_m4);
	UpperModel upper4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<opi1<<" > "<<opi2<<" : "<<std::endl;	// CAS int > int		: retourne true
	if (*upper1.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false

	std::cout<<opd1<<" > "<<opd2<<" : "<<std::endl;	// CAS double > double	: retourne true
	if (*upper2.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opi1<<" > "<<opd2<<" : "<<std::endl;	// CAS int > double		: retourne true
	if (*upper3.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	if(!upper4.execute().bool_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingPrime(){
	std::cout <<"----------Test de prime--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = 19;
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

	/*var 5*/
	var_type_value5.int_type	= nullptr;
	var_type_value5.double_type = nullptr;
	var_type_value5.bool_type	= &opb1;
	
	
	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("1", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	VariableModel var_m5("5", var_type_value5);
	
	
	/*Nes classes d'addition*/
	PrimeModel prime1(&var_m1); //Un int
	PrimeModel prime4(&var_m2); //Un int
	PrimeModel prime2(&var_m3); //un double
	PrimeModel prime3(&var_m5); //un bool
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 19
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<" Prime("<<opi1<<") : "<<std::endl;	// CAS Prime(int)		: retourne false
	if (*prime1.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" Prime("<<opi2<<") : "<<std::endl;	// CAS Prime(int)		: retourne true
	if (*prime4.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" Prime("<<opd1<<") : "<<std::endl;	// CAS Prime(double)	: retourne error
	if (!prime2.execute().bool_type)
		std::cout<<"error"<<std::endl;	// CAS double			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS double	: retourne error
	
	std::cout<<" Prime("<<(opb1?"true":"false")<<") : "<<std::endl;	// CAS int > double		: retourne true
	if (!prime3.execute().bool_type)
		std::cout<<"Error"<<std::endl;	// CAS bool			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS bool		: retourne error
}

void unitTestingMax(){
	std::cout <<"----------Test de max--------"<< std::endl;
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
	MaxModel max1(&var_m1, &var_m2);
	MaxModel max2(&var_m3, &var_m4);
	MaxModel max3(&var_m1, &var_m4);
	MaxModel max4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<opi2<<") est : "<<*max1.execute().int_type<<std::endl;	// CAS int+int			: retourne 966
	std::cout<<"La valeur de l'addition (mult "<<opd1<<" et "<<opd2<<") est : "<<*max2.execute().double_type<<std::endl; // CAS double+double	: retourne 28433.47572
	std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<opd2<<") est : "<<*max3.execute().double_type<<std::endl; // CAS int+double		: retourne 1791.972
	
	if(!max4.execute().double_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingMin(){
	std::cout <<"----------Test de min--------"<< std::endl;
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
	MinModel min1(&var_m1, &var_m2);
	MinModel min2(&var_m3, &var_m4);
	MinModel min3(&var_m1, &var_m4);
	MinModel min4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<opi2<<") est : "<<*min1.execute().int_type<<std::endl;	// CAS int+int			: retourne 966
	std::cout<<"La valeur de l'addition (mult "<<opd1<<" et "<<opd2<<") est : "<<*min2.execute().double_type<<std::endl; // CAS double+double	: retourne 28433.47572
	std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<opd2<<") est : "<<*min3.execute().double_type<<std::endl; // CAS int+double		: retourne 1791.972
	
	if(!min4.execute().double_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}


