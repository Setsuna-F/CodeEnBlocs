#ifndef ASSIGNMENT_BLOC_HPP
#define ASSIGNMENT_BLOC_HPP


#ifdef __APPLESOKA__
#include "Bloc.hpp"
#include "assignmentmodel.hpp"
#else
#include "Bloc.hpp"
#include "model/assignmentmodel.hpp"
#endif

namespace satap {
	class AssignmentBloc : public Bloc, public AssignmentModel {
	public:
		AssignmentBloc(State::Context context);
		AssignmentBloc(State::Context context, VariableModel* firstOperand, BlockCompositeModel* secondOperand);
	};
}
#endif
