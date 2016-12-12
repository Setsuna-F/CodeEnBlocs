#ifndef INPUT_BLOC_HPP
#define INPUT_BLOC_HPP

#include <gui/blocs/Bloc.hpp>
#include <model\inputmodel.hpp>

namespace satap {
	class InputBloc : public GUI::Bloc, public InputModel {
	public:
		InputBloc(State::Context context);
	};
}
#endif