#include "equalmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

EqualModel::EqualModel() {
	//
}

EqualModel::EqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

EqualModel::EqualModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

EqualModel::~EqualModel() {
	//
}

sct_type EqualModel::execute() {
	sct_type firstOperand;
	firstOperand.int_type		=nullptr;
	firstOperand.double_type	=nullptr;
	firstOperand.bool_type		=nullptr;
	
	sct_type secondOperand;
	secondOperand.int_type		=nullptr;
	secondOperand.double_type	=nullptr;
	secondOperand.bool_type		=nullptr;
	
	sct_type res;
	res.int_type		=nullptr;
	res.double_type		=nullptr;
	res.bool_type		=nullptr;
	
	firstOperand = this->BinaryModel::getFirstOperand()->execute();
	secondOperand = this->BinaryModel::getSecondOperand()->execute();
	
	bool isinteger=true; // cette variable va nous servir a voir si les deux param sont des int ou des doubles
	double res_first=0;
	double res_second=0;
	
	/*Premiere operande int ou double*/
	if(firstOperand.int_type)
		res_first=*firstOperand.int_type;
	else if(firstOperand.double_type){
		isinteger=false;
		res_first=*firstOperand.double_type;
	}
	/*cas erreur*/
	else
		return res;
	
	
	/*Seconde operande int ou double*/
	if(secondOperand.int_type)
		res_second=*secondOperand.int_type;
	else if(secondOperand.double_type){
		isinteger=false;
		res_second=*secondOperand.double_type;
	}
	/*cas erreur*/
	else
		return res;
	
	
	bool res_bool=false;
	if (res_first == res_second)
		res_bool = true;
	
	res.bool_type=&res_bool;
	std::fflush(stdout);
	
	return res;
}
