#include "multBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::MultBloc::MultBloc(State::Context context) :
	Bloc(context) {}

satap::MultBloc::MultBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context),
	MultModel(firstOperand, secondOperand) {}

satap::MultBloc::MultBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context),
	MultModel(binaryModel) {}
