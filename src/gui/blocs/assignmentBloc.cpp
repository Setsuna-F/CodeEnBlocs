#include "assignmentBloc.hpp"

satap::AssignmentBloc::AssignmentBloc(State::Context context) :
	Bloc(context, AssignementBlocType) {}

satap::AssignmentBloc::AssignmentBloc(State::Context context, VariableModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context, AssignementBlocType),
	AssignmentModel(firstOperand, secondOperand) {}
