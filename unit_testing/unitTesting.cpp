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

#include "input.hpp"
#include "output.hpp"
#include "variableList.hpp"




void globalTests(){
	std::cout<<"////////////////////////"<<std::endl;
	std::cout<<"///unit testing begin///"<<std::endl;
	std::cout<<"////////////////////////"<<std::endl;
	
	std::cout<<"   | INPUT |   "<<std::endl;
	testInput();
	
	std::cout<<"   | OUTPUT |   "<<std::endl;
	testOutput();
	
	std::cout<<"   | VARIABLELIST |   "<<std::endl;
	testVariableList();
	
	std::cout<<"//////////////////////"<<std::endl;
	std::cout<<"///unit testing end///"<<std::endl;
	std::cout<<"//////////////////////"<<std::endl;
}



void testVariableList(){
	std::cout<<"Test de VariableList: "<<std::endl;

	VariableList vl;
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

	std::cout<<"Size of variableList is : "<<vl.size()<<std::endl;
}


void testOutput(){
	std::cout<<"Test de Output: "<<std::endl;
	std::cout<<"Test du contructeur avec param: "<<std::endl;

	std::vector<std::string> v;
	v.push_back("stella");
	v.push_back("stello");
	v.push_back("stelli");
	Output outv(v);
	outv.clear();
	std::cout<<"Test du contructeur sans param: "<<std::endl;
	Output out;
	out.push("soka");
	out.push("soda");
	out.clear();
}


void testInput(){
 	///////////Test unitaire des input.
	///////////Constructeur avec parametre:
	std::cout<<"Test de Input: "				 <<std::endl;
	std::cout<<"Test du contructeur avec param: "<<std::endl;
	std::stack<std::string> vs;
	vs.push("stella");
	vs.push("stello");
	vs.push("stelli");
	Input invs(vs);
	if(invs.size()!=3)	std::cout<<"Test has FAILED: "	<<invs.size()<<"!=3"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<invs.size()<<"==3"<<std::endl;
	/*---------------------------*/

	std::string v1 = invs.pop();
	if(v1!="stelli")	std::cout<<"Test has FAILED: "	<<v1<<"!=stelli"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<v1<<"==stelli"<<std::endl;
	if(invs.size()!=2)	std::cout<<"Test has FAILED: "	<<invs.size()<<"!=2"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<invs.size()<<"==2"<<std::endl;
	/*---------------------------*/

	
	std::string v2 = invs.pop();
	if(v2!="stello")	std::cout<<"Test has FAILED: "	<<v2		 <<"!=stello"<<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<v2		 <<"==stello"<<std::endl;
	if(invs.size()!=1)	std::cout<<"Test has FAILED: "	<<invs.size()<<"!=1"	 <<std::endl;
	else				std::cout<<"Test SUCCESS: "		<<invs.size()<<"==1"	 <<std::endl;
	/*---------------------------*/
	
	///////////Constructeur sans parametre:
	std::cout<<"Test du contructeur sans param: "<<std::endl;
	Input in;
	in.push("soka");
	in.push("soja");
	in.push("soya");
	in.push("jojo");
	in.push("soda");
	if(in.size()!=5) std::cout<<"Test has FAILED: "	<<in.size()<<"!=5"<<std::endl;
	else			 std::cout<<"Test SUCCESS: "	<<in.size()<<"==5"<<std::endl;
	/*---------------------------*/

	std::string v3 = in.pop();
	if(v3!="soda")	std::cout<<"Test has FAILED: "	<<v3		<<"!=soda"<<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<v3		<<"==soda"<<std::endl;
	if(in.size()!=4)std::cout<<"Test has FAILED: "	<<in.size() <<"!=4"	  <<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<in.size() <<"==4"	  <<std::endl;
	/*---------------------------*/
	
	std::string v4 = in.pop();
	if(v4!="jojo")	std::cout<<"Test has FAILED: "	<<v4		<<"!=jojo"<<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<v4		<<"==jojo"<<std::endl;
	if(in.size()!=3)std::cout<<"Test has FAILED: "	<<in.size() <<"!=3"	  <<std::endl;
	else			std::cout<<"Test SUCCESS: "		<<in.size() <<"==3"	  <<std::endl;
	/*---------------------------*/
}
