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

PrimeModel::PrimeModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

PrimeModel::PrimeModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

PrimeModel::~PrimeModel() {
	//
}


sct_type PrimeModel::execute() {
	sct_type op;
	op.int_type		=nullptr;
	op.double_type	=nullptr;
	op.bool_type	=nullptr;
	
	op = this->UnaryModel::getOperand()->execute();
	if(op.int_type){
		bool result = this->isPrime((*op.int_type), (*op.int_type)/2);
		op.bool_type	= &result;
	}
	else{
		op.int_type		=nullptr;
		op.double_type	=nullptr;
		op.bool_type	=nullptr;
	}
	return op;
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
