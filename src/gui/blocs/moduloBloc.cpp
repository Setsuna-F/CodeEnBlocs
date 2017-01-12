#include "moduloBloc.hpp"

/*
 *
 * Description :
 *
 *
*/

satap::ModuloBloc::ModuloBloc(State::Context context) :
	Bloc(context) {}

satap::ModuloBloc::ModuloBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context),
	ModuloModel(firstOperand, secondOperand) {}

satap::ModuloBloc::ModuloBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context),
	ModuloModel(binaryModel) {}
