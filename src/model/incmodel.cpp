#include "incmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

IncModel::IncModel() {
	//
}

IncModel::IncModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

IncModel::IncModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

IncModel::~IncModel() {
	//
}

sct_type IncModel::execute() {
	/*int operand = std::stoi( this->UnaryModel::getOperand()->execute() );

	operand--;
	return std::to_string(operand);*/
	
	sct_type res;
	return res;
}
