#include "assignmentmodel.hpp"

using namespace satap;

AssignmentModel::AssignmentModel() {
	//
}
/*
 * 
 *
 */
AssignmentModel::AssignmentModel(VariableModel variable, BlockCompositeModel * block) {
	this->_variable = variable;
	this->_block = block;
}
AssignmentModel::~AssignmentModel() {
	//
}

VariableModel AssignmentModel::getVariable() {
	return this->_variable;
}

BlockCompositeModel * AssignmentModel::getBlock() {
	return this->_block;
}

sct_type AssignmentModel::execute() {
	sct_type value;
	value.int_type 	= nullptr;
	value.double_type 	= nullptr;
	value.bool_type 	= nullptr;

    value = (this->_block)->execute();
    this->_variable.setValue(value);

	return value;
}
