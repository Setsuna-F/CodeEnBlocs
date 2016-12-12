#include <gui/blocs/addBloc.hpp>

satap::AddBloc::AddBloc(State::Context context) :
	Bloc(context) {}

satap::AddBloc::AddBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand) :
	Bloc(context),
	AddModel(firstOperand, secondOperand) {}

satap::AddBloc::AddBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context),
	AddModel(binaryModel) {}