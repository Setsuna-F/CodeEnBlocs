#include "divmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

DivModel::DivModel() {
	//
}

DivModel::DivModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

DivModel::DivModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

DivModel::~DivModel() {
	//
}

std::string DivModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );
	if (secondOperand == 0)
		return "Arthmetic Exception Error : denominator nul";
	int result = firstOperand / secondOperand;
	return std::to_string(result);
}

std::string DivModel::getCategory() {
	return "arithmetic";
}
