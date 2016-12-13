#include <gui/blocs/variableBloc.hpp>

satap::VariableBloc::VariableBloc(State::Context context) :
	Bloc(context),
	VariableModel() {
	setText("Var");
}

satap::VariableBloc::VariableBloc(State::Context context, std::string name, sct_type value) :
	Bloc(context),
	VariableModel(name, value) {
	setText("Var" + name);
}