#include "notmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

NotModel::NotModel() {
	//
}

NotModel::NotModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

NotModel::NotModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

NotModel::~NotModel() {
	//
}

sct_type NotModel::execute() {
	sct_type op;
	op.int_type		= nullptr;
	op.double_type	= nullptr;
	op.bool_type	= nullptr;
	
	op = this->UnaryModel::getOperand()->execute();
	
	/*Cas bool*/
	if(op.bool_type){
		bool res_tmp = *op.bool_type;
		res_tmp = !res_tmp;
		op.bool_type = &res_tmp;
		std::fflush(stdout);
	}
	/*Cas erreur*/
	else{
		op.int_type		= nullptr;
		op.double_type	= nullptr;
		op.bool_type	= nullptr;
		return op;
	}
	
	return op;
}
