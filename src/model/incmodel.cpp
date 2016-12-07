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

std::string IncModel::execute() {
	int operand = std::stoi( this->UnaryModel::getOperand()->execute() );

	operand--;
	return std::to_string(operand);
}
