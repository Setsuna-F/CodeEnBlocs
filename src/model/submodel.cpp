#include "submodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

SubModel::SubModel() {
	//
}

SubModel::SubModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

SubModel::SubModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

SubModel::~SubModel() {
	//
}

sct_type SubModel::execute() {
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
		int res_int=(*firstOperand.int_type)-(*secondOperand.int_type);
		res.int_type = &res_int;
		return res;
	}
	/*cas double*/
	else if(firstOperand.double_type && secondOperand.double_type){
		double res_double=(*firstOperand.double_type)-(*secondOperand.double_type);
		res.double_type = &res_double;
		return res;
	}
	/*cas erreur*/
	else{
		return res;
	}
}

std::string SubModel::getCategory() {
	return "arithmetic";
}
