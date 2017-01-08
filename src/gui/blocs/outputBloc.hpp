#ifndef OUTPUT_BLOC_HPP
#define OUTPUT_BLOC_HPP

#ifdef __APPLESOKA__
#include "Bloc.hpp"
#include "outputmodel.hpp"
#else
#include "Bloc.hpp"
#include "model/outputmodel.hpp"
#endif


namespace satap {
	class OutputBloc : public Bloc, public OutputModel {
	public:
		OutputBloc(State::Context context, OutputListModel* outPutList);
	};
}
#endif
