#include "evenBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::EvenBloc::EvenBloc(State::Context context) :
	Bloc(context) {}

satap::EvenBloc::EvenBloc(State::Context context, BlockCompositeModel* Operand) :
	Bloc(context),
	EvenModel(Operand) {}

satap::EvenBloc::EvenBloc(State::Context context, const UnaryModel& unaryModel) :
	Bloc(context),
	EvenModel(unaryModel) {}
