#ifndef INPUT_BLOC_HPP
#define INPUT_BLOC_HPP

#ifdef __APPLESOKA__
#include "Bloc.hpp"
#include "inputmodel.hpp"
#else
#include "Bloc.hpp"
#include "model/inputmodel.hpp"
#endif

namespace satap {
	class InputBloc : public Bloc, public InputModel {
	public:
		InputBloc(State::Context context, InputListModel* inputList);
	};
}
#endif
