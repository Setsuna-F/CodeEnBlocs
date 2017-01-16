#include "subBloc.hpp"

satap::SubBloc::SubBloc(State::Context context) :
	Bloc(context, SubBlocType) {}

satap::SubBloc::SubBloc(State::Context context, BlockCompositeModel* &firstOperand, BlockCompositeModel* &secondOperand) :
	Bloc(context, SubBlocType),
	SubModel(firstOperand, secondOperand) {}

satap::SubBloc::SubBloc(State::Context context, const BinaryModel& binaryModel) :
	Bloc(context, SubBlocType),
	SubModel(binaryModel) {}
