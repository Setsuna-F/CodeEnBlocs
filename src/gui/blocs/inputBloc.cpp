#include "inputBloc.hpp"

satap::InputBloc::InputBloc(State::Context context, InputListModel* inputList) :
	Bloc(context),
	InputModel(inputList) {}
