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
	/*int operand = std::stoi( this->UnaryModel::getOperand()->execute() );

	operand++;
	return std::to_string(operand);*/
	
	sct_type res;
	return res;
}
