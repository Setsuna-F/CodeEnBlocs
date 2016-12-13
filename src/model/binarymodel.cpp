#include "binarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

BinaryModel::BinaryModel() {
	//
}

BinaryModel::BinaryModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) {
	this->_firstOperand = firstOperand;
	this->_secondOperand = secondOperand;
}

BinaryModel::BinaryModel(const BinaryModel & binaryModel) {
	this->_firstOperand = binaryModel._firstOperand;
	this->_secondOperand = binaryModel._secondOperand;
}

BinaryModel::~BinaryModel() {
	//
}

BlockCompositeModel* BinaryModel::getFirstOperand() {
	return this->_firstOperand;
}

void BinaryModel::setFirstOperand(BlockCompositeModel* operand) {
	this->_firstOperand = operand;
}

BlockCompositeModel* BinaryModel::getSecondOperand() {
	return this->_secondOperand;
}

void BinaryModel::setSecondOperand(BlockCompositeModel* operand) {
	this->_secondOperand = operand;
}


