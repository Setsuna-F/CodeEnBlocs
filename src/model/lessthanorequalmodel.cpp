#include "lessthanorequalmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

LessThanOrEqualModel::LessThanOrEqualModel() {
	//
}

LessThanOrEqualModel::LessThanOrEqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

LessThanOrEqualModel::LessThanOrEqualModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

LessThanOrEqualModel::~LessThanOrEqualModel() {
	//
}

std::string LessThanOrEqualModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand <= secondOperand ? true : false;
	return std::to_string(result);
}
