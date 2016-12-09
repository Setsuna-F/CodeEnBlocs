#include "differentmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

DifferentModel::DifferentModel() {
	//
}

DifferentModel::DifferentModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

DifferentModel::DifferentModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

DifferentModel::~DifferentModel() {
	//
}

sct_type DifferentModel::execute() {
	/*int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand != secondOperand ? true : false;
	return std::to_string(result);*/
	
	sct_type res;
	return res;
}
