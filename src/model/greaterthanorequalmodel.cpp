#include "greaterthanorequalmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

GreaterThanOrEqualModel::GreaterThanOrEqualModel() {
	//
}

GreaterThanOrEqualModel::GreaterThanOrEqualModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

GreaterThanOrEqualModel::GreaterThanOrEqualModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

GreaterThanOrEqualModel::~GreaterThanOrEqualModel() {
	//
}

sct_type GreaterThanOrEqualModel::execute() {
	/*int firstOperand = std::stoi( this->BinaryModel::getFirstOperand()->execute() );
	int secondOperand = std::stoi( this->BinaryModel::getSecondOperand()->execute() );

	bool result = firstOperand >= secondOperand ? true : false;
	return std::to_string(result);*/
	
	sct_type res;
	return res;
}
