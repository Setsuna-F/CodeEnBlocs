#include "primemodel.hpp"

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

std::string PrimeModel::execute() {
	return "the addition";
}

std::string PrimeModel::getCategory() {
	return "other";
}
