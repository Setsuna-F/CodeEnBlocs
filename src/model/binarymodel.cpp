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

BinaryModel::BinaryModel(BlockModel* firstOperand, BlockCompositeModel* secondOperand) {
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

BlockModel* BinaryModel::getFirstOperand() {
	return this->_firstOperand;
}

void BinaryModel::setFirstOperand(BlockModel* operand) {
	this->_firstOperand = operand;
}

BlockCompositeModel* BinaryModel::getSecondOperand() {
	return this->_secondOperand;
}

void BinaryModel::setSecondOperand(BlockCompositeModel* operand) {
	this->_secondOperand = operand;
}

int BinaryModel::getNbElements() {
	if (_firstOperand == NULL && _secondOperand == NULL) {
		return 1;
	}
	else if (_firstOperand == NULL) {
		return 1 + _secondOperand->getNbElements();
	}
	else if (_secondOperand == NULL) {
		return 1 + _firstOperand->getNbElements();
	}
	else {
		int gauche = _firstOperand->getNbElements();
		int droite = _secondOperand->getNbElements();
		return 1 + gauche + droite;
	}
}
