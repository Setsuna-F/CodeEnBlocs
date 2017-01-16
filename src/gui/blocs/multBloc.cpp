#include "multBloc.hpp"

satap::MultBloc::MultBloc(State::Context context) :
	Bloc(context, MultBlocType) {}

satap::MultBloc::MultBloc(State::Context context, BlockCompositeModel* &firstOperand, BlockCompositeModel* &secondOperand) :
	Bloc(context, MultBlocType),
	MultModel(firstOperand, secondOperand) {}

satap::MultBloc::MultBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context, MultBlocType),
	MultModel(binaryModel) {}
