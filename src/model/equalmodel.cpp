#include "equalmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

EqualModel::EqualModel() {
	//
}

EqualModel::EqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

EqualModel::EqualModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

EqualModel::~EqualModel() {
	//
}

std::string EqualModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand == secondOperand ? true : false;
	return std::to_string(result);
}
