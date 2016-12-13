#include "assignmentBloc.hpp"

satap::AssignmentBloc::AssignmentBloc(State::Context context) :
	Bloc(context) {}

satap::AssignmentBloc::AssignmentBloc(State::Context context, VariableModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context),
	AssignmentModel(firstOperand, secondOperand) {}