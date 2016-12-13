#ifndef ASSIGNMENT_BLOC_HPP
#define ASSIGNMENT_BLOC_HPP

#include "Bloc.hpp"
#include "model/assignmentmodel.hpp"

namespace satap {
	class AssignmentBloc : public Bloc, public AssignmentModel {
	public:
		AssignmentBloc(State::Context context);
		AssignmentBloc(State::Context context, VariableModel variable, BlockCompositeModel & block);
	};
}
#endif
