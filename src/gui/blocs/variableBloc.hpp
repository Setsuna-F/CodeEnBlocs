#ifndef VARIABLE_BLOC_HPP
#define VARIABLE_BLOC_HPP

#ifdef __APPLESOKA__
#include "Bloc.hpp"
#include "variablemodel.hpp"
#else
#include "Bloc.hpp"
#include "model/variablemodel.hpp"
#endif


namespace satap {
	class VariableBloc : public Bloc, public VariableModel {
		public:
			VariableBloc(State::Context context, std::string name, sct_type value);
			VariableBloc(State::Context context);
	};
}
#endif
