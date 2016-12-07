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

std::string AbsModel::execute() {
	int operand = std::stoi( this->UnaryModel::getOperand()->execute() );

	operand = operand >= 0 ? operand : operand * (-1);
	return std::to_string(operand);
}
