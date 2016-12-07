#include "primemodel.hpp"

#include "tools.h"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

PrimeModel::PrimeModel() {
	//
}

PrimeModel::PrimeModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) : BinaryModel(firstOperand, secondOperand) {
	//
}

PrimeModel::PrimeModel(const BinaryModel & binaryModel) : BinaryModel(binaryModel) {
	//
}

PrimeModel::~PrimeModel() {
	//
}

sct_type PrimeModel::execute() {
	sct_type res;
	return res;
}

std::string PrimeModel::getCategory() {
	return "other";
}
