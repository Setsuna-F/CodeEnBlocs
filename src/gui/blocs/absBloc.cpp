#include "absBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::AbsBloc::AbsBloc(State::Context context) :
	Bloc(context) {}

satap::AbsBloc::AbsBloc(State::Context context, BlockCompositeModel* Operand) :
	Bloc(context),
	AbsModel(Operand) {}

satap::AbsBloc::AbsBloc(State::Context context, const UnaryModel& unaryModel) :
	Bloc(context),
	AbsModel(unaryModel) {}
