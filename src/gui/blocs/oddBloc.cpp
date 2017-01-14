#include "oddBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::OddBloc::OddBloc(State::Context context) :
	Bloc(context) {}

satap::OddBloc::OddBloc(State::Context context, BlockCompositeModel* Operand) :
	Bloc(context),
	OddModel(Operand) {}

satap::OddBloc::OddBloc(State::Context context, const UnaryModel& unaryModel) :
	Bloc(context),
	OddModel(unaryModel) {}
