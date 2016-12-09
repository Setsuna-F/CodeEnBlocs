#include "andmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

AndModel::AndModel() {
	//
}

AndModel::AndModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

AndModel::AndModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

AndModel::~AndModel() {
	//
}

sct_type AndModel::execute() {
	/*int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand && secondOperand ? true : false;
	return std::to_string(result);*/
	
	sct_type res;
	return res;
}
