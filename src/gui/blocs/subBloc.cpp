#include "subBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::SubBloc::SubBloc(State::Context context) :
	Bloc(context) {}

satap::SubBloc::SubBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context),
	SubModel(firstOperand, secondOperand) {}

satap::SubBloc::SubBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context),
	SubModel(binaryModel) {}
