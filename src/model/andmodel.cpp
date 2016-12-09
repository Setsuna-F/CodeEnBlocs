#include "andmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

AndModel::AndModel() {
	//
}

AndModel::AndModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

AndModel::AndModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

AndModel::~AndModel() {
	//
}

sct_type AndModel::execute() {
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
	
	firstOperand  = this->BinaryModel::getFirstOperand()->execute();
	secondOperand = this->BinaryModel::getSecondOperand()->execute();

	/*Cas bool*/
	if(firstOperand.bool_type && secondOperand.bool_type){
		bool res_and = (*firstOperand.bool_type) && (*secondOperand.bool_type);
		res.bool_type = &res_and;
		std::fflush(stdout);
	}
	/*cas erreur*/
	else
		return res;
	
	return res;
}
