#include "outputBloc.hpp"

satap::OutputBloc::OutputBloc(State::Context context, OutputListModel* outputList) :
	Bloc(context, OutputBlocType),
	OutputModel(outputList) {}
