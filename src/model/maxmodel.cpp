#include "maxmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

MaxModel::MaxModel() {
	//
}

MaxModel::MaxModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

MaxModel::MaxModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

MaxModel::~MaxModel() {
	//
}

std::string MaxModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	int result = firstOperand > secondOperand ? firstOperand : secondOperand;
	return std::to_string(result);
}
