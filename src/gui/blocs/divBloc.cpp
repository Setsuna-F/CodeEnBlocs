#include "divBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::DivBloc::DivBloc(State::Context context) :
	Bloc(context) {}

satap::DivBloc::DivBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context),
	DivModel(firstOperand, secondOperand) {}

satap::DivBloc::DivBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context),
	DivModel(binaryModel) {}
