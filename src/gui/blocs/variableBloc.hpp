#ifndef VARIABLE_BLOC_HPP
#define VARIABLE_BLOC_HPP

#include <gui/blocs/Bloc.hpp>
#include <model\variablemodel.hpp>

namespace satap {
	class VariableBloc : public GUI::Bloc, public VariableModel {
		public:
			VariableBloc(State::Context context, std::string name, sct_type value);
			VariableBloc(State::Context context);
	};
}
#endif