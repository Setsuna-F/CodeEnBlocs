#include "lessthanmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

LessThanModel::LessThanModel() {
	//
}

LessThanModel::LessThanModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

LessThanModel::LessThanModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

LessThanModel::~LessThanModel() {
	//
}

std::string LessThanModel::execute() {
	int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand < secondOperand ? true : false;
	return std::to_string(result);
}
