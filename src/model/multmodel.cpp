#include "multmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

MultModel::MultModel() {
	//
}

MultModel::MultModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

MultModel::MultModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

MultModel::~MultModel() {
	//
}

std::string MultModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );
	
	int result = firstOperand * secondOperand;
	return std::to_string(result);
}

std::string MultModel::getCategory() {
	return "arithmetic";
}
