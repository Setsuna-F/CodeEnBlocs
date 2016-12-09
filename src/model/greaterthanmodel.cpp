#include "greaterthanmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

GreaterThanModel::GreaterThanModel() {
	//
}

GreaterThanModel::GreaterThanModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

GreaterThanModel::GreaterThanModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

GreaterThanModel::~GreaterThanModel() {
	//
}

sct_type GreaterThanModel::execute() {
	/*int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand > secondOperand ? true : false;
	return std::to_string(result);*/
	
	sct_type res;
	return res;
}
