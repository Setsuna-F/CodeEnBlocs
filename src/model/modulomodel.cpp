#include "modulomodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

ModuloModel::ModuloModel() {
	//
}

ModuloModel::ModuloModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

ModuloModel::ModuloModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

ModuloModel::~ModuloModel() {
	//
}

std::string ModuloModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );
	if (secondOperand == 0)
		return "Arthmetic Exception Error : denominator nul";
	int result = firstOperand % secondOperand;
	return std::to_string(result);
}

std::string ModuloModel::getCategory() {
	return "arithmetic";
}
