#include "addmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

AddModel::AddModel() {
	//
}

AddModel::AddModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

AddModel::AddModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

AddModel::~AddModel() {
	//
}

std::string AddModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );
	
	int result = firstOperand + secondOperand;
	return std::to_string(result);
}

std::string AddModel::getCategory() {
	return "arithmetic";
}
