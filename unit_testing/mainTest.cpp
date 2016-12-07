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




class c{
public:
	template<typename Type>
	Type sokafunc(){
		Type go=6667;
		return go;
	}
};



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
	int soka;
	int * pi;
	std::cout << "int is: " << typeid(int).name() << '\n';
	std::cout << "  i is: " << typeid(soka).name() << '\n';
	std::cout << " pi is: " << typeid(pi).name() << '\n';
	std::cout << "*pi is: " << typeid(*pi).name() << '\n';
	
	
	
	std::cout << std::endl;
	char sokac;
	char * pic;
	std::cout << "int is: " << typeid(char).name() << '\n';
	std::cout << "  i is: " << typeid(sokac).name() << '\n';
	std::cout << " pi is: " << typeid(pic).name() << '\n';
	std::cout << "*pi is: " << typeid(*pic).name() << '\n';
	
	
	
	
	std::cout << std::endl;
	bool sokab;
	bool * pib;
	std::cout << "int is: " << typeid(bool).name() << '\n';
	std::cout << "  i is: " << typeid(sokab).name() << '\n';
	std::cout << " pi is: " << typeid(pib).name() << '\n';
	std::cout << "*pi is: " << typeid(*pib).name() << '\n';
	
	
	
	
	std::cout << std::endl;
	double sokad;
	double * pid;
	std::cout << "int is: " << typeid(double).name() << '\n';
	std::cout << "  i is: " << typeid(sokad).name() << '\n';
	std::cout << " pi is: " << typeid(pid).name() << '\n';
	std::cout << "*pi is: " << typeid(*pid).name() << '\n';
	
	


	std::cout << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << "**************| FIN |**************" << std::endl;
	std::cout << "***********************************" << std::endl;

	
	
	
	return 0;
}

