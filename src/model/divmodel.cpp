#include "divmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

DivModel::DivModel() {
	//
}

DivModel::DivModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

DivModel::DivModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

DivModel::~DivModel() {
	//
}

sct_type DivModel::execute() {
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

	/*cas int*/
	if(firstOperand.int_type && secondOperand.int_type){
		if((*secondOperand.int_type) == 0){
			return res;
		}
		int res_int=(*firstOperand.int_type)/(*secondOperand.int_type);
		res.int_type = &res_int;
		return res;
	}
	/*cas double*/
	else if(firstOperand.double_type && secondOperand.double_type){
		if((*secondOperand.double_type) == 0){
			return res;
		}
		double res_double=(*firstOperand.double_type)/(*secondOperand.double_type);
		res.double_type = &res_double;
		return res;
	}
	/*cas erreur*/
	else{
		return res;
	}
}

std::string DivModel::getCategory() {
	return "arithmetic";
}
