#include "ormodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

OrModel::OrModel() {
	//
}

OrModel::OrModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

OrModel::OrModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

OrModel::~OrModel() {
	//
}

sct_type OrModel::execute() {
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

	/*Cas bool*/
	if(firstOperand.bool_type && secondOperand.bool_type){
		bool res_and = (*firstOperand.bool_type) || (*secondOperand.bool_type);
		res.bool_type = new bool(res_and);
		std::fflush(stdout);
	}
	/*cas erreur*/
	else
		return res;

	return res;
}
