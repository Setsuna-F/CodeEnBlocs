#include "greaterthanorequalmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

GreaterThanOrEqualModel::GreaterThanOrEqualModel() {
	//
}

GreaterThanOrEqualModel::GreaterThanOrEqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

GreaterThanOrEqualModel::GreaterThanOrEqualModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

GreaterThanOrEqualModel::~GreaterThanOrEqualModel() {
	//
}

std::string GreaterThanOrEqualModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand >= secondOperand ? true : false;
	return std::to_string(result);
}
