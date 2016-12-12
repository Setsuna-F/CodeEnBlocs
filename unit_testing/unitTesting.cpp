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

#include "../src/model/variablelistmodel.hpp"
#include "../src/model/outputlistmodel.hpp"
#include "../src/model/inputlistmodel.hpp"
#include "../src/model/variablemodel.hpp"
#include "../src/model/outputmodel.hpp"
#include "../src/model/loopmodel.hpp"
#include "../src/model/ifmodel.hpp"

#include "../src/model/modulomodel.hpp"
#include "../src/model/multmodel.hpp"
#include "../src/model/divmodel.hpp"
#include "../src/model/addmodel.hpp"
#include "../src/model/submodel.hpp"

#include "../src/model/uppermodel.hpp"
#include "../src/model/primemodel.hpp"
#include "../src/model/maxmodel.hpp"
#include "../src/model/minmodel.hpp"

#include "../src/model/greaterthanorequalmodel.hpp"
#include "../src/model/lessthanorequalmodel.hpp"
#include "../src/model/greaterthanmodel.hpp"
#include "../src/model/differentmodel.hpp"
#include "../src/model/lessthanmodel.hpp"
#include "../src/model/equalmodel.hpp"
#include "../src/model/andmodel.hpp"
#include "../src/model/notmodel.hpp"
#include "../src/model/absmodel.hpp"
#include "../src/model/decmodel.hpp"
#include "../src/model/incmodel.hpp"
#include "../src/model/ormodel.hpp"
#include "../src/model/incmodel.hpp"
#include "../src/model/decmodel.hpp"

#include "../src/tools.h"


#include "inputmodel.hpp"
#include "InstructionBlocks.hpp"


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
/*
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
	out.clear();*/
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


void testInputlistINT(InputListModel &inputlist, int val_1, int val_2, int val_3){
	
	/*---------------------------*/
	std::cout<<std::endl;
	std::cout<<"Test de la taille d'un inputlist"<<std::endl;
	if(inputlist.size()!=3)	std::cout<<"Test a echoué: le nombre d'element dans l'input n'est pas exact : "			<<inputlist.size()<<"!=3"<<std::endl;
	else					std::cout<<"Test est un succé: il y a le bon nombre d'element qui a ete enregistré : "	<<inputlist.size()<<"==3"<<std::endl;
	
	/*---------------------------*/
	std::cout<<std::endl;
	std::cout<<"Test de la validité de chaque element de l'input (Si les entrées sont bonnes)"<<std::endl;
	std::cout<<std::endl<<"1ER ELEMENT:"<<std::endl;
	sct_type v1 = inputlist.pop();
	if(v1.int_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un int nulle"	<<std::endl;
	else
		if(*v1.int_type==val_3)
			std::cout<<"Le test est un succé: La valeur pour un int est bien "<< *v1.int_type <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< *v1.int_type <<" au lieu de "<< val_3 << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==2)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==2"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=2"	<<std::endl;
	
	
	std::cout<<std::endl<<"2EME ELEMENT:"<<std::endl;
	sct_type v2 = inputlist.pop();
	if(v2.int_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un int nulle"	<<std::endl;
	else
		if(*v2.int_type==val_2)
			std::cout<<"Le test est un succé: La valeur pour un int est bien "<< *v2.int_type <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< *v2.int_type <<" au lieu de "<< val_2 << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==1)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==1"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=1"	<<std::endl;
	
	
	
	
	
	std::cout<<std::endl<<"3EME ELEMENT:"<<std::endl;
	sct_type v3 = inputlist.pop();
	if(v3.int_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un int nulle"	<<std::endl;
	else
		if(*v3.int_type==val_1)
			std::cout<<"Le test est un succé: La valeur pour un int est bien "<< *v3.int_type <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< *v3.int_type <<" au lieu de "<< val_1 << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==0)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==0"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=0"	<<std::endl;
	
	
	
	std::cout<<std::endl<<"4EME ELEMENT:"<<std::endl;
	sct_type v4 = inputlist.pop();
	if(v4.int_type == nullptr)
		std::cout<<"Le test est un succé: La valeur pour un int est bien nulle car il n'y a plus d'element"	<<std::endl;
	else
		std::cout<<"Le test a echoué: Il ne devrait pas y avoir d'element (On devrait recuperer une valeur 'nullptr')"	<<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==0)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==0"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=0"	<<std::endl;
}

void testInputlistDOUBLE(InputListModel &inputlist, double val_1, double val_2, double val_3){
	
	/*---------------------------*/
	std::cout<<std::endl;
	std::cout<<"Test de la taille d'un inputlist"<<std::endl;
	if(inputlist.size()!=3)	std::cout<<"Test a echoué: le nombre d'element dans l'input n'est pas exact : "			<<inputlist.size()<<"!=3"<<std::endl;
	else					std::cout<<"Test est un succé: il y a le bon nombre d'element qui a ete enregistré : "	<<inputlist.size()<<"==3"<<std::endl;
	
	/*---------------------------*/
	std::cout<<std::endl;
	std::cout<<"Test de la validité de chaque element de l'input (Si les entrées sont bonnes)"<<std::endl;
	std::cout<<std::endl<<"1ER ELEMENT:"<<std::endl;
	sct_type v1 = inputlist.pop();
	if(v1.double_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un double nulle"	<<std::endl;
	else
		if(*v1.double_type==val_3)
			std::cout<<"Le test est un succé: La valeur pour un double est bien "<< *v1.double_type <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< *v1.double_type <<" au lieu de "<< val_3 << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==2)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==2"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=2"	<<std::endl;
	
	
	std::cout<<std::endl<<"2EME ELEMENT:"<<std::endl;
	sct_type v2 = inputlist.pop();
	if(v2.double_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un double nulle"	<<std::endl;
	else
		if(*v2.double_type==val_2)
			std::cout<<"Le test est un succé: La valeur pour un double est bien "<< *v2.double_type <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< *v2.double_type <<" au lieu de "<< val_2 << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==1)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==1"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=1"	<<std::endl;
	
	
	
	
	
	std::cout<<std::endl<<"3EME ELEMENT:"<<std::endl;
	sct_type v3 = inputlist.pop();
	if(v3.double_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un double nulle"	<<std::endl;
	else
		if(*v3.double_type==val_1)
			std::cout<<"Le test est un succé: La valeur pour un double est bien "<< *v3.double_type <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< *v3.double_type <<" au lieu de "<< val_1 << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==0)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==0"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=0"	<<std::endl;
	
	
	
	std::cout<<std::endl<<"4EME ELEMENT:"<<std::endl;
	sct_type v4 = inputlist.pop();
	if(v4.double_type == nullptr)
		std::cout<<"Le test est un succé: La valeur pour un double est bien nulle car il n'y a plus d'element"	<<std::endl;
	else
		std::cout<<"Le test a echoué: Il ne devrait pas y avoir d'element (On devrait recuperer une valeur 'nullptr')"	<<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==0)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==0"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=0"	<<std::endl;
}

void testInputlistBOOL(InputListModel &inputlist, bool val_1, bool val_2){
	
	/*---------------------------*/
	std::cout<<std::endl;
	std::cout<<"Test de la taille d'un inputlist"<<std::endl;
	if(inputlist.size()!=2)	std::cout<<"Test a echoué: le nombre d'element dans l'input n'est pas exact : "			<<inputlist.size()<<"!=2"<<std::endl;
	else					std::cout<<"Test est un succé: il y a le bon nombre d'element qui a ete enregistré : "	<<inputlist.size()<<"==2"<<std::endl;
	
	/*---------------------------*/
	std::cout<<std::endl;
	std::cout<<"Test de la validité de chaque element de l'input (Si les entrées sont bonnes)"<<std::endl;
	std::cout<<std::endl<<"1ER ELEMENT:"<<std::endl;
	sct_type v1 = inputlist.pop();
	if(v1.bool_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un bool nulle"	<<std::endl;
	else
		if(*v1.bool_type==val_2)
			std::cout<<"Le test est un succé: La valeur pour un bool est bien "<< (*v1.bool_type?"TRUE":"FALSE") <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< (*v1.bool_type?"TRUE":"FALSE") <<" au lieu de "<< (val_2?"TRUE":"FALSE") << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==1)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==1"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=1"	<<std::endl;
	
	
	std::cout<<std::endl<<"2EME ELEMENT:"<<std::endl;
	sct_type v2 = inputlist.pop();
	if(v2.bool_type == nullptr)
		std::cout<<"Le test a echoué: La valeur pour un bool nulle"	<<std::endl;
	else
		if(*v2.bool_type==val_1)
			std::cout<<"Le test est un succé: La valeur pour un bool est bien "<< (*v2.bool_type?"TRUE":"FALSE") <<std::endl;
		else
			std::cout<<"Le test a echoué: La valeur recupéré n'est pas celle attendu ( "<< (*v2.bool_type?"TRUE":"FALSE") <<" au lieu de "<<  (val_1?"TRUE":"FALSE")  << " )" <<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==0)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==0"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=0"	<<std::endl;
	
	
	
	
	std::cout<<std::endl<<"3EME ELEMENT:"<<std::endl;
	sct_type v4 = inputlist.pop();
	if(v4.bool_type == nullptr)
		std::cout<<"Le test est un succé: La valeur pour un int est bien nulle car il n'y a plus d'element"	<<std::endl;
	else
		std::cout<<"Le test a echoué: Il ne devrait pas y avoir d'element (On devrait recuperer une valeur 'nullptr')"	<<std::endl;
	
	std::cout<<std::endl;
	std::cout<<"Test pour savoir si la liste d'input a retiré son element"<<std::endl;
	if(inputlist.size()==0)	std::cout<<"Le test est un succé: "	<<inputlist.size()<<"==0"	<<std::endl;
	else					std::cout<<"Le test a echoué: "		<<inputlist.size()<<"!=0"	<<std::endl;
}

void testInputListModel(){
 	///////////Test unitaire des input.
	///////////Constructeur avec parametre:
	std::cout<<"Test de InputModel: "			 <<std::endl;
	std::cout<<"Test du contructeur sans param: "<<std::endl;
	
	InputListModel	inputlist;		/*Notre liste d'input*/
	sct_type val_input1;
	sct_type val_input2;
	sct_type val_input3;
	
	
	std::cout<<"\t/*------------------------*/"<<std::endl;
	std::cout<<"\t/*            Int         */"<<std::endl;
	std::cout<<"\t/*------------------------*/"<<std::endl;
	
	/*init la liste des input avec 3 entier de type int */
	/*On crée nos valeurs*/
	int val_int1=-42;	/* init avec un nombre negatif */
	int val_int2=0;		/* init avec un nombre nul */
	int val_int3=666;	/* init avec un nombre positif */
	
	/*On les donnes dans notre structure*/
	val_input1.int_type		= &val_int1;
	val_input1.double_type	= nullptr;
	val_input1.bool_type	= nullptr;
	
	val_input2.int_type		= &val_int2;
	val_input2.double_type	= nullptr;
	val_input2.bool_type	= nullptr;
	
	val_input3.int_type		= &val_int3;
	val_input3.double_type	= nullptr;
	val_input3.bool_type	= nullptr;
	
	/*On ajoute nos entré a notre liste d'input*/
	inputlist.push(val_input1);
	inputlist.push(val_input2);
	inputlist.push(val_input3);
	
	testInputlistINT(inputlist, val_int1, val_int2, val_int3);
	
	
	
	std::cout<<"\t/*----------------------------*/"<<std::endl;
	std::cout<<"\t/*            Double          */"<<std::endl;
	std::cout<<"\t/*----------------------------*/"<<std::endl;
	
	
	/*init la liste des input avec 3 entier de type int */
	/*On crée nos valeurs*/
	double val_double1=-42.666;		/* init avec un nombre negatif */
	double val_double2=0.1234;		/* init avec un nombre nul */
	double val_double3=666.00934;	/* init avec un nombre positif */
	
	/*On les donnes dans notre structure*/
	val_input1.int_type		= nullptr;
	val_input1.double_type	= &val_double1;
	val_input1.bool_type	= nullptr;
	
	val_input2.int_type		= nullptr;
	val_input2.double_type	= &val_double2;
	val_input2.bool_type	= nullptr;
	
	val_input3.int_type		= nullptr;
	val_input3.double_type	= &val_double3;
	val_input3.bool_type	= nullptr;
	
	/*On ajoute nos entré a notre liste d'input*/
	inputlist.push(val_input1);
	inputlist.push(val_input2);
	inputlist.push(val_input3);
	
	
	testInputlistDOUBLE(inputlist, val_double1, val_double2, val_double3);
	
	
	std::cout<<"\t/*--------------------------*/"<<std::endl;
	std::cout<<"\t/*            Bool          */"<<std::endl;
	std::cout<<"\t/*--------------------------*/"<<std::endl;
	
	
	/*init la liste des input avec 3 entier de type int */
	/*On crée nos valeurs*/
	bool val_bool1=true;		/* init avec un nombre negatif */
	bool val_bool2=false;		/* init avec un nombre nul */
	
	/*On les donnes dans notre structure*/
	val_input1.int_type		= nullptr;
	val_input1.double_type	= nullptr;
	val_input1.bool_type	= &val_bool1;
	
	val_input2.int_type		= nullptr;
	val_input2.double_type	= nullptr;
	val_input2.bool_type	= &val_bool2;
	
	/*On ajoute nos entré a notre liste d'input*/
	inputlist.push(val_input1);
	inputlist.push(val_input2);
	
	
	testInputlistBOOL(inputlist, val_bool1, val_bool2);
	
	
	/*---------------------------*/
	std::cout<<std::endl;
	///////////Constructeur sans parametre:
	std::cout<<"Test du contructeur avec param: "<<std::endl;
	
	std::cout<<"\t/*------------------------*/"<<std::endl;
	std::cout<<"\t/*            Int         */"<<std::endl;
	std::cout<<"\t/*------------------------*/"<<std::endl;
	
	val_int1=-42;	/* init avec un nombre negatif */
	val_int2=0;		/* init avec un nombre nul */
	val_int3=666;	/* init avec un nombre positif */
	
	/*On les donnes dans notre structure*/
	val_input1.int_type		= &val_int1;
	val_input1.double_type	= nullptr;
	val_input1.bool_type	= nullptr;
	
	val_input2.int_type		= &val_int2;
	val_input2.double_type	= nullptr;
	val_input2.bool_type	= nullptr;
	
	val_input3.int_type		= &val_int3;
	val_input3.double_type	= nullptr;
	val_input3.bool_type	= nullptr;
	
	/* On cree notre pile et on ajoute les elements dans cette pile */
	std::stack<sct_type> val_input_stack_int;
	val_input_stack_int.push(val_input1);
	val_input_stack_int.push(val_input2);
	val_input_stack_int.push(val_input3);
	
	InputListModel inputlist_INT_avec_param(val_input_stack_int);
	testInputlistINT(inputlist_INT_avec_param, val_int1, val_int2, val_int3);

	
	std::cout<<"\t/*----------------------------*/"<<std::endl;
	std::cout<<"\t/*            Double          */"<<std::endl;
	std::cout<<"\t/*----------------------------*/"<<std::endl;
	
	
	/*init la liste des input avec 3 entier de type int */
	/*On crée nos valeurs*/
	val_double1=-42.666;		/* init avec un nombre negatif */
	val_double2=0.1234;		/* init avec un nombre nul */
	val_double3=666.00934;	/* init avec un nombre positif */
	
	/*On les donnes dans notre structure*/
	val_input1.int_type		= nullptr;
	val_input1.double_type	= &val_double1;
	val_input1.bool_type	= nullptr;
	
	val_input2.int_type		= nullptr;
	val_input2.double_type	= &val_double2;
	val_input2.bool_type	= nullptr;
	
	val_input3.int_type		= nullptr;
	val_input3.double_type	= &val_double3;
	val_input3.bool_type	= nullptr;
	
	/*On ajoute nos entré a notre liste d'input*/
	std::stack<sct_type> val_input_stack_double;
	val_input_stack_double.push(val_input1);
	val_input_stack_double.push(val_input2);
	val_input_stack_double.push(val_input3);
	
	InputListModel inputlist_DOUBLE_avec_param(val_input_stack_double);
	testInputlistDOUBLE(inputlist_DOUBLE_avec_param, val_double1, val_double2, val_double3);
	
	
	std::cout<<"\t/*--------------------------*/"<<std::endl;
	std::cout<<"\t/*            Bool          */"<<std::endl;
	std::cout<<"\t/*--------------------------*/"<<std::endl;
	
	
	/*init la liste des input avec 3 entier de type int */
	/*On crée nos valeurs*/
	val_bool1=true;		/* init avec un nombre negatif */
	val_bool2=false;		/* init avec un nombre nul */
	
	/*On les donnes dans notre structure*/
	val_input1.int_type		= nullptr;
	val_input1.double_type	= nullptr;
	val_input1.bool_type	= &val_bool1;
	
	val_input2.int_type		= nullptr;
	val_input2.double_type	= nullptr;
	val_input2.bool_type	= &val_bool2;
	
	/*On ajoute nos entré a notre liste d'input*/
	std::stack<sct_type> val_input_stack_bool;
	val_input_stack_bool.push(val_input1);
	val_input_stack_bool.push(val_input2);
	
	InputListModel inputlist_BOOL_avec_param(val_input_stack_bool);
	testInputlistBOOL(inputlist_BOOL_avec_param, val_bool1, val_bool2);
	
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

void unitTestingGreaterThan(){
	std::cout <<"----------Test de greater than--------"<< std::endl;
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
	GreaterThanModel upper1(&var_m1, &var_m2);
	GreaterThanModel upper2(&var_m3, &var_m4);
	GreaterThanModel upper3(&var_m1, &var_m4);
	GreaterThanModel upper4(&var_m1, &var_m5);
	
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

void unitTestingLessThan(){
	std::cout <<"----------Test de less than--------"<< std::endl;
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
	LessThanModel lessthan1(&var_m1, &var_m2);
	LessThanModel lessthan2(&var_m3, &var_m4);
	LessThanModel lessthan3(&var_m1, &var_m4);
	LessThanModel lessthan4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<opi1<<" < "<<opi2<<" : "<<std::endl;	// CAS int < int		: retourne true
	if (*lessthan1.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opd1<<" < "<<opd2<<" : "<<std::endl;	// CAS double < double	: retourne true
	if (*lessthan2.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opi1<<" < "<<opd2<<" : "<<std::endl;	// CAS int < double		: retourne true
	if (*lessthan3.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	if(!lessthan4.execute().bool_type)
		std::cout<<"La valeur de (less than "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de (less than "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}


void unitTestingLessThanOrEqual(){
	std::cout <<"----------Test de less or equal‡ than--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = 42;
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
	LessThanOrEqualModel lessorequal1(&var_m1, &var_m2);
	LessThanOrEqualModel lessorequal2(&var_m3, &var_m4);
	LessThanOrEqualModel lessorequal3(&var_m1, &var_m4);
	LessThanOrEqualModel lessorequal4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<opi1<<" <= "<<opi2<<" : "<<std::endl;	// CAS int > int		: retourne true
	if (*lessorequal1.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opd1<<" <= "<<opd2<<" : "<<std::endl;	// CAS double > double	: retourne true
	if (*lessorequal2.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opi1<<" <= "<<opd2<<" : "<<std::endl;	// CAS int > double		: retourne true
	if (*lessorequal3.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	if(!lessorequal4.execute().bool_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingGreaterThanOrEqual(){
	std::cout <<"----------Test de greater or equal than--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = 42;
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
	GreaterThanOrEqualModel greaterorequal1(&var_m1, &var_m2);
	GreaterThanOrEqualModel greaterorequal2(&var_m3, &var_m4);
	GreaterThanOrEqualModel greaterorequal3(&var_m1, &var_m4);
	GreaterThanOrEqualModel greaterorequal4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<opi1<<" >= "<<opi2<<" : "<<std::endl;	// CAS int > int		: retourne true
	if (*greaterorequal1.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opd1<<" >= "<<opd2<<" : "<<std::endl;	// CAS double > double	: retourne false
	if (*greaterorequal2.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opi1<<" >= "<<opd2<<" : "<<std::endl;	// CAS int > double		: retourne true
	if (*greaterorequal3.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	if(!greaterorequal4.execute().bool_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}

void unitTestingEqual(){
	std::cout <<"----------Test de equal--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = 42;
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
	EqualModel equal1(&var_m1, &var_m2);
	EqualModel equal2(&var_m3, &var_m4);
	EqualModel equal3(&var_m1, &var_m4);
	EqualModel equal4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<opi1<<" == "<<opi2<<" : "<<std::endl;	// CAS int > int		: retourne true
	if (*equal1.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opd1<<" == "<<opd2<<" : "<<std::endl;	// CAS double > double	: retourne false
	if (*equal2.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opi1<<" == "<<opd2<<" : "<<std::endl;	// CAS int > double		: retourne false
	if (*equal3.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	if(!equal4.execute().bool_type)
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (mult "<<opi1<<" et "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
}


void unitTestingDifferent(){
	std::cout <<"----------Test de different--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = 42;
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
	DifferentModel different1(&var_m1, &var_m2);
	DifferentModel different2(&var_m3, &var_m4);
	DifferentModel different3(&var_m1, &var_m4);
	DifferentModel different4(&var_m1, &var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<opi1<<" != "<<opi2<<" : "<<std::endl;	// CAS int > int		: retourne true
	if (*different1.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opd1<<" != "<<opd2<<" : "<<std::endl;	// CAS double > double	: retourne false
	if (*different2.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	std::cout<<opi1<<" != "<<opd2<<" : "<<std::endl;	// CAS int > double		: retourne false
	if (*different3.execute().bool_type)
		std::cout<<"true"<<std::endl;	// CAS int+int			: retourne true
	else
		std::cout<<"false"<<std::endl;	// CAS int+int			: retourne false
	
	if(!different4.execute().bool_type)
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



void unitTestingAnd(){
	std::cout <<"----------Test de and--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	sct_type var_type_value6;
	
	int opi1 = 42;
	double opd1 = 666.42;
	bool opb1 = true;
	bool opb2 = true;
	bool opb3 = false;
	bool opb4 = false;
	
	/*var 1*/
	var_type_value1.int_type	= &opi1;
	var_type_value1.double_type = nullptr;
	var_type_value1.bool_type	= nullptr;
	
	/*var 2*/
	var_type_value2.int_type	= nullptr;
	var_type_value2.double_type = &opd1;
	var_type_value2.bool_type	= nullptr;
	
	/*var 3*/
	var_type_value3.int_type	= nullptr;
	var_type_value3.double_type = nullptr;
	var_type_value3.bool_type	= &opb1;
	
	/*var 4*/
	var_type_value4.int_type	= nullptr;
	var_type_value4.double_type = nullptr;
	var_type_value4.bool_type	= &opb2;
	
	/*var 5*/
	var_type_value5.int_type	= nullptr;
	var_type_value5.double_type = nullptr;
	var_type_value5.bool_type	= &opb3;
	
	/*var 6*/
	var_type_value6.int_type	= nullptr;
	var_type_value6.double_type = nullptr;
	var_type_value6.bool_type	= &opb4;

	
	
	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("1", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	VariableModel var_m4("5", var_type_value4);
	VariableModel var_m5("5", var_type_value5);
	VariableModel var_m6("5", var_type_value6);
	
	
	/*Nes classes d'addition*/
	AndModel and1(&var_m1, &var_m2); //Un int et double (int and double)
	AndModel and2(&var_m3, &var_m4); //un bool et bool (true and true)
	AndModel and3(&var_m5, &var_m6); //un bool et bool (false and false)
	AndModel and4(&var_m4, &var_m5); //un bool et bool (true and false)
	AndModel and5(&var_m1, &var_m3); //un int et bool  (int and true)

	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.double_type<<std::endl; // retourne  666.42
	
	std::cout<<"La valeur de vtv3 "<<(*var_type_value3.double_type?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value4.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne false
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value6.bool_type)?"true":"false")<<std::endl; // retourne false
	
	
	std::cout<<" And("<<(opb1?"true":"false")<<", "<< (opb2?"true":"false") <<") : "<<std::endl;	// CAS Prime(int)		: retourne true
	if (and2.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" And("<<(opb3?"true":"false")<<", "<< (opb4?"true":"false") <<") : "<<std::endl;	// CAS Prime(int)		: retourne false
	if (*and3.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	std::cout<<" And("<<(opb2?"true":"false")<<", "<< (opb3?"true":"false") <<") : "<<std::endl;	// CAS Prime(int)		: retourne false
	if (*and4.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" And("<<opi1<<", "<<opd1<<") : "<<std::endl;	// CAS Add(int, double)						: retourne error
	if (!and1.execute().bool_type)
		std::cout<<"error"<<std::endl;	// CAS double			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS double	: retourne error
	
	std::cout<<" And("<<opi1<<", "<<(opb1?"true":"false") <<") : "<<std::endl;	// CAS Add(int, true)		: retourne error
	if (!and5.execute().bool_type)
		std::cout<<"Error"<<std::endl;	// CAS bool			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS bool		: retourne error
}

void unitTestingOr(){
	std::cout <<"----------Test de or--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	sct_type var_type_value6;
	
	int opi1 = 42;
	double opd1 = 666.42;
	bool opb1 = true;
	bool opb2 = true;
	bool opb3 = false;
	bool opb4 = false;
	
	/*var 1*/
	var_type_value1.int_type	= &opi1;
	var_type_value1.double_type = nullptr;
	var_type_value1.bool_type	= nullptr;
	
	/*var 2*/
	var_type_value2.int_type	= nullptr;
	var_type_value2.double_type = &opd1;
	var_type_value2.bool_type	= nullptr;
	
	/*var 3*/
	var_type_value3.int_type	= nullptr;
	var_type_value3.double_type = nullptr;
	var_type_value3.bool_type	= &opb1;
	
	/*var 4*/
	var_type_value4.int_type	= nullptr;
	var_type_value4.double_type = nullptr;
	var_type_value4.bool_type	= &opb2;
	
	/*var 5*/
	var_type_value5.int_type	= nullptr;
	var_type_value5.double_type = nullptr;
	var_type_value5.bool_type	= &opb3;
	
	/*var 6*/
	var_type_value6.int_type	= nullptr;
	var_type_value6.double_type = nullptr;
	var_type_value6.bool_type	= &opb4;
	
	
	
	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("1", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	VariableModel var_m4("5", var_type_value4);
	VariableModel var_m5("5", var_type_value5);
	VariableModel var_m6("5", var_type_value6);
	
	
	/*Nes classes d'addition*/
	OrModel or1; //Un int et double (int and double)
	OrModel or2(&var_m3, &var_m4); //un bool et bool (true and true)
	OrModel or3(&var_m5, &var_m6); //un bool et bool (false and false)
	OrModel or4(&var_m4, &var_m5); //un bool et bool (true and false)
	OrModel or5(&var_m1, &var_m3); //un int et bool  (int and true)
	
	or1.setFirstOperand(&var_m1);
	or1.setSecondOperand(&var_m2);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.double_type<<std::endl; // retourne  666.42
	
	std::cout<<"La valeur de vtv3 "<<(*var_type_value3.double_type?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value4.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne false
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value6.bool_type)?"true":"false")<<std::endl; // retourne false
	
	
	std::cout<<" Or("<<(opb1?"true":"false")<<", "<< (opb2?"true":"false") <<") : "<<std::endl;	// CAS Or(true, true)		: retourne true
	if (or2.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" Or("<<(opb3?"true":"false")<<", "<< (opb4?"true":"false") <<") : "<<std::endl;	// CAS Or(false, false): retourne false
	if (*or3.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	std::cout<<" Or("<<(opb2?"true":"false")<<", "<< (opb3?"true":"false") <<") : "<<std::endl;	// CAS Or(true, false)		: retourne true
	if (*or4.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" Or("<<opi1<<", "<<opd1<<") : "<<std::endl;	// CAS Or(int, double)						: retourne error
	if (!or1.execute().bool_type)
		std::cout<<"error"<<std::endl;	// CAS double			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS double	: retourne error
	
	std::cout<<" Or("<<opi1<<", "<<(opb1?"true":"false") <<") : "<<std::endl;	// CAS Or(int, true)		: retourne error
	if (!or5.execute().bool_type)
		std::cout<<"Error"<<std::endl;	// CAS bool			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS bool		: retourne error
}

void unitTestingInc(){
	std::cout <<"----------Test de inc--------"<< std::endl;
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
	IncModel inc1(&var_m1);
	IncModel inc2(&var_m3);
	IncModel inc3(&var_m1);
	IncModel inc4(&var_m5);
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	std::cout<<"La valeur de l'addition (inc "<<opi1<<") est : "<<*inc1.execute().int_type<<std::endl;	// CAS int+int			: retourne 65
	std::cout<<"La valeur de l'addition (inc "<<opd1<<") est : "<<*inc2.execute().double_type<<std::endl; // CAS double+double	: retourne 709.086
	std::cout<<"La valeur de l'addition (inc "<<opi1<<") est : "<<*inc3.execute().int_type<<std::endl; // CAS int+double		: retourne 84.666
	
	if(!inc4.execute().double_type)
		std::cout<<"La valeur de l'addition (inc "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (inc "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error
	
}


void unitTestingDec(){
	std::cout <<"----------Test de dec--------"<< std::endl;
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
	DecModel dec1(&var_m1);
	DecModel dec2(&var_m3);
	DecModel dec3(&var_m1);
	DecModel dec4(&var_m5);

	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 23

	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	std::cout<<"La valeur de vtv4 "<<*var_type_value4.double_type<<std::endl; // retourne 42.666

	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true

	std::cout<<"La valeur de l'addition (inc "<<opi1<<") est : "<<*dec1.execute().int_type<<std::endl;	// CAS int+int			: retourne 65
	std::cout<<"La valeur de l'addition (inc "<<opd1<<") est : "<<*dec2.execute().double_type<<std::endl; // CAS double+double	: retourne 709.086
	std::cout<<"La valeur de l'addition (inc "<<opi1<<") est : "<<*dec3.execute().int_type<<std::endl; // CAS int+double		: retourne 84.666

	if(!dec4.execute().double_type)
		std::cout<<"La valeur de l'addition (inc "<<(opb1?"T":"F")<<") est un bien un cas d'erreur "<<std::endl; // CAS int+true	: retourne error
	else
		std::cout<<"La valeur de l'addition (inc "<<(opb1?"T":"F")<<"), ERROR IL Y A UN PROBLEME ! "<<std::endl; // CAS int+true	: retourne error

}

void unitTestingAbs(){
	std::cout <<"----------Test de abs--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	sct_type var_type_value4;
	sct_type var_type_value5;
	
	int opi1 = 42;
	int opi2 = -19;
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
	AbsModel abs1; //Un int
	AbsModel abs2(&var_m2); //Un int
	AbsModel abs3(&var_m3); //un double
	AbsModel abs4(&var_m5); //un bool
	
	
	abs1.setOperand(&var_m1);
	
	
	std::cout<<"La valeur de vtv1 "<<*var_type_value1.int_type<<std::endl; // retourne 42
	
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 19
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	
	std::cout<<"La valeur de vtv5 "<<((*var_type_value5.bool_type)?"true":"false")<<std::endl; // retourne true
	
	
	std::cout<<" ABS("<<opi1<<") : "<<std::endl;	// CAS Prime(int)		: retourne false
	if (*abs1.execute().int_type)
		std::cout<<*abs1.execute().int_type<<std::endl;
	else
		std::cout<<"Erreur"<<std::endl;
	
	
	std::cout<<" ABS("<<opi2<<") : "<<std::endl;	// CAS Prime(int)		: retourne true
	if (*abs2.execute().int_type)
		std::cout<<*abs2.execute().int_type<<std::endl;
	else
		std::cout<<"Erreur"<<std::endl;
	
	
	std::cout<<" ABS("<<opd1<<") : "<<std::endl;	// CAS Prime(double)	: retourne error
	if (*abs3.execute().double_type)
		std::cout<<*abs3.execute().double_type<<std::endl;	// CAS double			: retourne error
	else
		std::cout<<"Erreur"<<std::endl;	// CAS double	: retourne error

	std::cout<<" ABS("<<(opb1?"true":"false")<<") : "<<std::endl;	// CAS int > double		: retourne true
	if (!abs4.execute().bool_type)
		std::cout<<"Error"<<std::endl;	// CAS bool			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS bool		: retourne error
}

void unitTestingNot(){
	std::cout <<"----------Test de not--------"<< std::endl;
	sct_type var_type_value1;
	sct_type var_type_value2;
	sct_type var_type_value3;
	
	int opi1 = 42;
	int opi2 = -19;
	double opd1 = 666.42;
	double opd2 = 42.666;
	bool opb1 = true;
	
	/*var 1*/
	var_type_value1.int_type	= nullptr;
	var_type_value1.double_type = nullptr;
	var_type_value1.bool_type	= &opb1;
	
	/*var 2*/
	var_type_value2.int_type	= &opi2;
	var_type_value2.double_type = nullptr;
	var_type_value2.bool_type	= nullptr;
	
	/*var 3*/
	var_type_value3.int_type	= nullptr;
	var_type_value3.double_type = &opd1;
	var_type_value3.bool_type	= nullptr;
	
	
	VariableModel var_m1("1", var_type_value1);
	VariableModel var_m2("1", var_type_value2);
	VariableModel var_m3("3", var_type_value3);
	
	
	/*Nes classes d'addition*/
	NotModel not1(&var_m1); //Un int
	NotModel not2(&var_m2); //Un int
	NotModel not3(&var_m3); //un double
	
	std::cout<<"La valeur de vtv1 "<<((*var_type_value1.bool_type)?"true":"false")<<std::endl; // retourne 42
	
	std::cout<<"La valeur de vtv2 "<<*var_type_value2.int_type<<std::endl; // retourne 19
	
	std::cout<<"La valeur de vtv3 "<<*var_type_value3.double_type<<std::endl; // retourne 666.42
	
	
	std::cout<<" not("<<((*var_type_value1.bool_type)?"true":"false")<<") : "<<std::endl;	// CAS Prime(int)		: retourne false
	if (*not1.execute().bool_type)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	
	
	std::cout<<" not("<<opi2<<") : "<<std::endl;	// CAS Prime(int)		: retourne true
	if (!not2.execute().bool_type)
		std::cout<<"error"<<std::endl;	// CAS double			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS double	: retourne error
	
	
	std::cout<<" not("<<opd1<<") : "<<std::endl;	// CAS Prime(double)	: retourne error
	if (!not3.execute().bool_type)
		std::cout<<"error"<<std::endl;	// CAS double			: retourne error
	else
		std::cout<<"Error donc probleme de conception (ne devrait pas atteindre cette condition)"<<std::endl;	// CAS double	: retourne error
	
}





void testInputModel(){
	std::cout <<"----------Test de input--------"<< std::endl;
	InputModel input;
	sct_type var_type1;
	sct_type var_type2;
	sct_type var_type3;
	
	int int_val1=42;
	int int_val2=23;
	int int_val3=666;
	
	
	var_type1.int_type	  = &int_val1;
	var_type1.double_type = nullptr;
	var_type1.bool_type	  = nullptr;
	
	
	var_type2.int_type	  = &int_val2;
	var_type2.double_type = nullptr;
	var_type2.bool_type	  = nullptr;
	
	
	var_type3.int_type	  = &int_val3;
	var_type3.double_type = nullptr;
	var_type3.bool_type	  = nullptr;
	
	satap::InputListModel inputList;
	inputList.push(var_type1);
	inputList.push(var_type2);
	inputList.push(var_type3);
	
	input.setInputList(inputList);
	
	size_t nbInput_deb = inputList.size();
	std::cout<<"Le nombre d'element dans inputList est de  "<< nbInput_deb <<std::endl;
	
	sct_type val_recupe;
	val_recupe =  input.execute();
	if(val_recupe.int_type){
		if(*val_recupe.int_type==int_val3)
			std::cout<<"Le test est un succé: la valeur est bien "<< *val_recupe.int_type << " = " << int_val3 <<std::endl;
		else
			std::cout<<"Le test a echoué: la valeur n'est pas bonne "<< *val_recupe.int_type <<"au lieu de "<< int_val3 <<std::endl;
	}
	size_t nbInput_fin = inputList.size();

	if(nbInput_fin == nbInput_deb-1)
		std::cout<<"Le test est un succé: Le nombre d'element dans inputList a bien ete decrementé "<< nbInput_fin <<std::endl;
	else
		std::cout<<"Le test a echoué: Le nombre d'element dans inputList n'a pas changé "<< nbInput_fin <<std::endl;

}




/* ================================================== */
/* ================================================== */
/* ================================================== */
/* ================================================== */


/*
// /----------AAAAAAA----------- /



class A{
public:
	A(int i):i(i){}
	virtual int getId(int id) = 0;
	int getI(){return i;}
	virtual std::vector<A*> getL() = 0;
private:
	int i;
};


int A::getId(int id){
	return -1;
}


std::vector<A*> A::getL(){
	
	std::vector<A*> vA;
	return vA;
}

// / ----------DDDDDDDD----------- /


class D: public A{
public:
	D(int i):A(i){}
	int getId(int id);
	virtual std::vector<A*> getL();
private:
};
int D::getId(int id){
	std::cout<<"D: [getID] id="<<id<<" = "<<getI()<<std::endl;
	if (id==getI()) {
		return id;
	}
	return -1;
}
std::vector<A*> D::getL(){
	
	std::vector<A*> vA;
	return vA;
}

// /----------CCCCCCC----------- /



class C: public A{
public:
	C(int i):A(i){
		l.push_back(new D(5));
	}
	void setC(A*);
	int getId(int id);
	std::vector<A*> getL();

private:
	std::vector<A*> l;
};




void C::setC(A* a){
	l.push_back(a);
}
std::vector<A*> C::getL(){return l;}

int C::getId(int id){
	std::cout<<"C: [getID] id="<<id<<" = "<<getI()<<std::endl;
	if (id==getI()) {
		return id;
	}
	A* ii=nullptr;
	int i=-1;
	for (std::vector<A*>::iterator it = this->l.begin(); it != this->l.end(); ++it){
		std::cout<<"C: [FOR] id="<<id<<" = "<<(*it)->getI()<<std::endl;
		if(id==(*it)->getI())
			ii = (*it);
		else
			 i = (*it)->getId(id);
	}
	return ii?ii->getI():i;
}






// /----------BBBBBB----------- /

class B: public A{
public:
	B(int i):A(i){
		l.push_back(new C(3));
		l.push_back(new D(4));
	}
	void setC(A*);
	std::vector<A*> getL();
	int getId(int id);
private:
	std::vector<A*> l;
};



void B::setC(A* a){
	l.push_back(a);
}
std::vector<A*> B::getL(){return l;}

int B::getId(int id){
	std::cout<<"B: [getID] id="<<id<<" = "<<getI()<<std::endl;
	
	if (id==getI()) {
		return id;
	}
	A* ii=nullptr;
	int i=-1;
	for (std::vector<A*>::iterator it = this->l.begin(); it != this->l.end(); ++it){
		std::cout<<"B: [FOR] id="<<id<<" = "<<(*it)->getI()<<std::endl;
		if(id==(*it)->getI())
			ii = (*it);
		else
			i = (*it)->getId(id);
	}

	return ii?ii->getI():i;
}
*/





















#include <time.h> //Ne pas oublier d'inclure le fichier time.h

void exempleExercice1(){
	
	std::cout<<"DEBUT DE L'EXERCICE 1"<<std::endl;
	std::cout<<std::endl;

	InputListModel			inputlist;		/*Notre liste d'input*/
	//OutputListModel			outputlist;		/*Notre liste d'output*/
	VariableListModel		variablelist;	/*Notre liste de variable*/
	InstructionBlockModel	code;			/*Notre liste d'instruction (pouvant etre tout et nimporte quels blocks)*/
	
	/*init la liste des input avec 3 entier au hasard */
	for (size_t i=0; i<3; i++) {
		int val_int=rand();
		sct_type val_input;
		val_input.int_type	 = &val_int;
		val_input.double_type= nullptr;
		val_input.bool_type	 = nullptr;

		inputlist.push(val_input);
	}
	
	/*Affichage de l'initialisation*/
	std::cout<<"Avant le CODE:"<<std::endl;

	std::cout<<"Les inputs:"<<std::endl;
	for (size_t i=0; i<3; i++) {
		std::cout<<">"<<i<<" |valeur: "<<inputlist.size()<<std::endl;
	}
	//std::cout<<"Les output:"<<std::endl;
	//for (size_t i=0; i<3; i++) {
	//	std::cout<<">"<<i<<" |valeur: "<<outputlist.size()<<std::endl;
	//}
	std::cout<<"Les variables:"<<std::endl;
	for (size_t i=0; i<3; i++) {
		std::cout<<">"<<i<<" |valeur: "<<variablelist.size()<<std::endl;
	}
	
	std::cout<<std::endl<<std::endl<<std::endl<<std::endl;

	
	sct_type val_input;
	int val_int=42;
	val_input.int_type	 = &val_int;
	val_input.double_type= nullptr;
	val_input.bool_type	 = nullptr;
	VariableModel v("42", val_input );


	InstructionBlockModel	code2;






	/* debut du code du joueur */
	//code.setBlock(new InputModel(inputlist), 0);
	code.setBlock(&v, "variable", 0);
	code.execute();
	
	//code.setBlock(new OutputModel, 0);
	

	/*
	 code2.setBlock(&code, 0);

	std::cout<<std::endl<<"idCode = "<<code.getId()<<std::endl<<std::endl;
	if (code.getBlockById(1)) {
		std::cout<<std::endl<<"idInput = "<<(*code.getBlockById(1)->execute().int_type)<<std::endl<<std::endl;
	}
	else
		std::cout<<std::endl<<"idInput = ERROR"<<std::endl<<std::endl;
	*/

	
	/*
	//std::cout<<std::endl<<"idCode2 = "<<code2.getId()<<std::endl<<std::endl;
	BlockModel* bm = code2.getBlockById(1);
	if (bm) {
		
		std::cout<<std::endl<<"idInput = "<<*(bm->execute().int_type)<< "     adres === "<< *v.execute().int_type <<std::endl<<std::endl;
	}
	else
		std::cout<<std::endl<<"idInput = ERROR"<<std::endl<<std::endl;
*/

	
	
	
	/* fin du code du joueur */
	
	
	
	
	
	
	//std::cout<<std::endl<<std::endl<<std::endl<<std::endl;

	
	/*Affichage du resultat*/
	/*std::cout<<"Apres le CODE:"<<std::endl;

	std::cout<<"Les inputs:"<<std::endl;
	for (size_t i=0; i<3; i++) {
		std::cout<<">"<<i<<" |valeur: "<<inputlist.size()<<std::endl;
	}
	std::cout<<"Les output:"<<std::endl;
	for (size_t i=0; i<3; i++) {
		std::cout<<">"<<i<<" |valeur: "<<outputlist.size()<<std::endl;
	}
	std::cout<<"Les variables:"<<std::endl;
	for (size_t i=0; i<3; i++) {
		std::cout<<">"<<i<<" |valeur: "<<variablelist.size()<<std::endl;
	}*/

	std::cout<<std::endl;
	std::cout<<"FIN DE L4EXERCICE 1"<<std::endl;


	/*
	B b(0);
	C c(1);
	D d(2);
	c.setC(&d);
	b.setC(&c);
	//std::cout<< "B0 " << b.getId(2) <<std::endl;
	std::cout<< "B1 " << b.getL().size() <<std::endl;
	std::cout<< "B2 " << b.getL()[0]->getL().size() <<std::endl;
	std::cout<< "B3 " << b.getL()[0]->getL()[0]->getL().size() <<std::endl;
	
	std::cout<< "------------------------ " <<std::endl;

	std::cout<< "C1 " << c.getL().size() <<std::endl;
	std::cout<< "C2 " << c.getL()[0]->getL().size() <<std::endl;
	//std::cout<< "C3 " << c.getL()[0]->getL()[0]->getL().size() <<std::endl;
	
	std::cout<< "------------------------ " <<std::endl;
	
	std::cout<< "B0 " << b.getI() <<std::endl;
	std::cout<< "B1 " << b.getL()[0]->getI() <<std::endl;
	std::cout<< "B2 " << b.getL()[0]->getL()[0]->getI() <<std::endl;
	
	std::cout<< "------------------------ " <<std::endl;

	std::cout<< "B0 " << b.getId(2) <<std::endl;*/

}

















/* ================================================== */
/* ================================================== */
/* ================================================== */
/* ================================================== */

