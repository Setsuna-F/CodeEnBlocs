#include "minmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

MinModel::MinModel() {
	//
}

MinModel::MinModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

MinModel::MinModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

MinModel::~MinModel() {
	//
}

std::string MinModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	int result = firstOperand < secondOperand ? firstOperand : secondOperand;
	return std::to_string(result);
}
