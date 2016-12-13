#include "assignmentmodel.hpp"

using namespace satap;

AssignmentModel::AssignmentModel() {
	//
}
/*
 * 
 *
 */
AssignmentModel::AssignmentModel(VariableModel* firstOperand, BlockCompositeModel* secondOperand)	:
	BinaryModel(firstOperand, secondOperand) { }

AssignmentModel::~AssignmentModel() {
	//
}

BlockModel * satap::AssignmentModel::getFirstOperand() {
	return _firstOperand;
}

void satap::AssignmentModel::setFirstOperand(BlockModel * operand) {
	_firstOperand = operand;
}

sct_type AssignmentModel::execute() {
	sct_type value;
	value.int_type 		= nullptr;
	value.double_type 	= nullptr;
	value.bool_type 	= nullptr;

    value = (_secondOperand)->execute();
	if (_firstOperand->getType() == OutputBlocType) {
		OutputModel* out = dynamic_cast<OutputModel*>(_firstOperand);
		out->setValue(value);
		out->execute();
	}
	else if (_firstOperand->getType() == VariableBlocType) {
		VariableModel* var = dynamic_cast<VariableModel*>(_firstOperand);
		var->setValue(value);
		var->execute();
	}

	return value;
}

typeBloc AssignmentModel::getType() {
	return AssignementBlocType;
}