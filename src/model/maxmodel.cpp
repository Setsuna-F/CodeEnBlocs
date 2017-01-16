#include "maxmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

MaxModel::MaxModel() {
	//
}

MaxModel::MaxModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

MaxModel::MaxModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

MaxModel::~MaxModel() {
	//
}

sct_type MaxModel::execute() {
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

	if(this->BinaryModel::getFirstOperand())
	firstOperand = this->BinaryModel::getFirstOperand()->execute();
	else
		return res;
	if(this->BinaryModel::getSecondOperand())
		secondOperand = this->BinaryModel::getSecondOperand()->execute();
	else
		return res;

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


	/*cas int*/
	if(isinteger){
		int res_max = res_first;
		if(res_first < res_second)
			res_max = res_second;
		res.int_type=new int(res_max);
		std::fflush(stdout);
	}
	/*cas double*/
	else{
		double res_max = res_first;
		if(res_first < res_second)
			res_max = res_second;
		res.double_type=new double(res_max);
		std::fflush(stdout);
	}

	return res;
}
