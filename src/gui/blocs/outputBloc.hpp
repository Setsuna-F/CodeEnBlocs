#ifndef OUTPUT_BLOC_HPP
#define OUTPUT_BLOC_HPP

#include "Bloc.hpp"
#include "model/outputmodel.hpp"

namespace satap {
	class OutputBloc : public Bloc, public OutputModel {
	public:
		OutputBloc(State::Context context, OutputListModel* outPutList);
	};
}
#endif
