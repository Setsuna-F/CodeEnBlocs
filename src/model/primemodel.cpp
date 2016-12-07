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

PrimeModel::PrimeModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

PrimeModel::PrimeModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

PrimeModel::~PrimeModel() {
	//
}

std::string PrimeModel::execute() {
	int operand = std::stoi( this->UnaryModel::getOperand()->execute() );
	
	bool result = this->isPrime(operand, operand/2);
	return std::to_string(result);
}

bool PrimeModel::isPrime(const int number, const int divider) {
	if (number == 1) 
		return true;
    if (divider == 1)
            return true;
    else {
            if (number % divider == 0)
                    return false;
            else
                    return isPrime(number, divider - 1);
    }

}
