#include <gui/blocs/variableBloc.hpp>

satap::VariableBloc::VariableBloc(State::Context context, std::string name, std::string value) :
	Bloc(context),
	VariableModel(name, value)
{

}