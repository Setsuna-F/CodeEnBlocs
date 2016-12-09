#include "decmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

DecModel::DecModel() {
	//
}

DecModel::DecModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

DecModel::DecModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

DecModel::~DecModel() {
	//
}

sct_type DecModel::execute() {
	sct_type operand;
	operand.int_type		=nullptr;
	operand.double_type		=nullptr;
	operand.bool_type		=nullptr;
	
	sct_type res;
	res.int_type		=nullptr;
	res.double_type		=nullptr;
	res.bool_type		=nullptr;
	
	operand = this->UnaryModel::getOperand()->execute();
	
	/*cas int*/
	if(operand.int_type){
		int res_add=*operand.int_type-1;
		res.int_type=&res_add;
		std::fflush(stdout);
	}
	/*cas double*/
	else if (operand.double_type){
		double res_add=*operand.double_type-1;
		res.double_type=&res_add;
		std::fflush(stdout);
	}
	
	return res;
}
