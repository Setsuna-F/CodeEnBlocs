#include "ormodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

OrModel::OrModel() {
	//
}

OrModel::OrModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

OrModel::OrModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

OrModel::~OrModel() {
	//
}

sct_type OrModel::execute() {
	/*int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand || secondOperand ? true : false;
	return std::to_string(result);*/
	
	sct_type res;
	return res;
}
