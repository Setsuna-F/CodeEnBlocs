#include "multmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

MultModel::MultModel() {
	//
}

MultModel::MultModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

MultModel::MultModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

MultModel::~MultModel() {
	//
}

sct_type MultModel::execute() {
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
		int res_add=res_second*res_first;
		//std::cout<<"val="<<res_second<<std::endl;
		//std::cout<<"val="<<res_first<<std::endl;
		//std::cout<<"val="<<res_add<<std::endl;
		//std::cout<<"val="<<res_second<<"*"<<res_first<<"="<<res_add<<std::endl;
		res.int_type=new int(res_add);
		std::fflush(stdout);
	}
	/*cas double*/
	else{
		double res_add=res_second*res_first;
		//std::cout<<"val="<<res_second<<std::endl;
		//std::cout<<"val="<<res_first<<std::endl;
		//std::cout<<"val="<<res_add<<std::endl;
		//std::cout<<"val="<<res_second<<"*"<<res_first<<"="<<res_add<<std::endl;
		res.double_type=new double(res_add);
		std::fflush(stdout);
	}

	return res;

}
