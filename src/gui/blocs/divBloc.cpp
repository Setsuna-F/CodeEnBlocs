#include "divBloc.hpp"

satap::DivBloc::DivBloc(State::Context context) :
	Bloc(context, DivBlocType) {}

satap::DivBloc::DivBloc(State::Context context, BlockCompositeModel* &firstOperand, BlockCompositeModel* &secondOperand) :
	Bloc(context, DivBlocType),
	DivModel(firstOperand, secondOperand) {}

satap::DivBloc::DivBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context, DivBlocType),
	DivModel(binaryModel) {}
