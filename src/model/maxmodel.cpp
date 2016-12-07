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
	
	firstOperand = this->BinaryModel::getFirstOperand()->execute();
	secondOperand = this->BinaryModel::getSecondOperand()->execute();
	
	/*cas int*/
	if(firstOperand.int_type && secondOperand.int_type){
		if((*firstOperand.int_type) > (*secondOperand.int_type)){
			res.int_type = firstOperand.int_type;
			return res;
		}
		res.int_type = secondOperand.int_type;
		return res;
	}
	/*cas double*/
	else if(firstOperand.double_type && secondOperand.double_type){
		if((*firstOperand.double_type) > (*secondOperand.double_type)){
			res.double_type = firstOperand.double_type;
			return res;
		}
		res.double_type = secondOperand.double_type;
		return res;
	}
	/*cas erreur*/
	else{
		return res;
	}
}

std::string MaxModel::getCategory() {
	return "other";
}
