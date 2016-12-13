#ifndef INPUT_BLOC_HPP
#define INPUT_BLOC_HPP

#include "Bloc.hpp"
#include "inputmodel.hpp"

namespace satap {
	class InputBloc : public GUI::Bloc, public InputModel {
	public:
		InputBloc(State::Context context);
	};
}
#endif
