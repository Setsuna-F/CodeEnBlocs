#include "absmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

AbsModel::AbsModel() {
	//
}

AbsModel::AbsModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

AbsModel::AbsModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

AbsModel::~AbsModel() {
	//
}

sct_type AbsModel::execute() {
	sct_type operand;
	operand.int_type		=nullptr;
	operand.double_type	    =nullptr;
	operand.bool_type		=nullptr;
	
	operand = this->UnaryModel::getOperand()->execute();
	
	/*Premiere operande int ou double*/
	if(operand.int_type) {
		std::fflush(stdout);
		*operand.int_type >= 0 ? *operand.int_type : *operand.int_type * (-1);
		operand.double_type	    =nullptr;
		operand.bool_type		=nullptr;
		return operand;
	}
	
	else if(operand.double_type){
		std::fflush(stdout);
		operand.int_type		=nullptr;
		*operand.double_type >= 0 ? *operand.double_type : *operand.double_type * (-1);
		operand.bool_type		=nullptr;
		return operand;
	}

	/*cas erreur*/
	else
		return operand;
}
