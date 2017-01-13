#include "modulomodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

ModuloModel::ModuloModel() {
	//
}

ModuloModel::ModuloModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

ModuloModel::ModuloModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

ModuloModel::~ModuloModel() {
	//
}

sct_type ModuloModel::execute() {
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
		int res_int=(*firstOperand.int_type)%(*secondOperand.int_type);
		res.int_type = new int(res_int);
		std::fflush(stdout);
		return res;
	}
	/*cas erreur*/
	else{
		return res;
	}
}
