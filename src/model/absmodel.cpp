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
	sct_type op;
	op.int_type		= nullptr;
	op.double_type	= nullptr;
	op.bool_type	= nullptr;

	op = this->UnaryModel::getOperand()->execute();

	if(op.int_type){
		int res_tmp = *op.int_type;
		if (res_tmp < 0) {
			res_tmp = res_tmp*(-1);
		}
		op.int_type = &res_tmp;
		std::fflush(stdout);
	}
	else if(op.double_type){
		double res_tmp = *op.double_type;
		if (res_tmp < 0) {
			res_tmp = res_tmp*(-1);
		}
		op.double_type = &res_tmp;
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
