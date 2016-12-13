#ifndef OUTPUT_BLOC_HPP
#define OUTPUT_BLOC_HPP

#include <gui/blocs/Bloc.hpp>
#include <model\outputmodel.hpp>

namespace satap {
	class OutputBloc : public Bloc, public OutputModel {
	public:
		OutputBloc(State::Context context);
	};
}
#endif