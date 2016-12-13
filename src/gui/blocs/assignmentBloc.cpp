#include "assignmentBloc.hpp"

satap::AssignmentBloc::AssignmentBloc(State::Context context) :
	Bloc(context) {}

satap::AssignmentBloc::AssignmentBloc(State::Context context, VariableModel variable, BlockCompositeModel & block) :
	Bloc(context),
	AssignmentModel(variable, block) {}