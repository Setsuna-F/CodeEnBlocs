#include "oddmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

OddModel::OddModel() {
	//
}

OddModel::OddModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

OddModel::OddModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

OddModel::~OddModel() {
	//
}

sct_type OddModel::execute() {
	sct_type op;
	op.int_type		= nullptr;
	op.double_type	= nullptr;
	op.bool_type	= nullptr;

    bool is_odd = false;

	op = this->UnaryModel::getOperand()->execute();

	if(op.int_type){
		int res_tmp = *op.int_type;
		if (res_tmp % 2 != 0) {
			is_odd = true;
		}
		op.bool_type = &is_odd;
		std::fflush(stdout);
	}
	else if(op.double_type){
		double res_tmp = *op.double_type;
        if (res_tmp % 2 != 0) {
			is_odd = true;
		}
		op.bool_type = &is_odd;
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
