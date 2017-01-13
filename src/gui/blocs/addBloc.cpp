#include "addBloc.hpp"

satap::AddBloc::AddBloc(State::Context context) :
	Bloc(context, AddBlocType) {}

satap::AddBloc::AddBloc(State::Context context, BlockCompositeModel* &firstOperand, BlockCompositeModel* &secondOperand) :
	Bloc(context, AddBlocType),
	AddModel(firstOperand, secondOperand) {}

satap::AddBloc::AddBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context, AddBlocType),
	AddModel(binaryModel) {}
