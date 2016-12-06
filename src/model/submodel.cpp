#include "submodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

SubModel::SubModel() {
	//
}

SubModel::SubModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

SubModel::SubModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

SubModel::~SubModel() {
	//
}

std::string SubModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );
	
	int result = firstOperand * secondOperand;
	return std::to_string(result);
}

std::string SubModel::getCategory() {
	return "arithmetic";
}
