#ifndef ADD_BLOC_HPP
#define ADD_BLOC_HPP


#ifdef __APPLESOKA__
#include "Bloc.hpp"
//#include "addmodel.hpp"
#else
#include "Bloc.hpp"
#include "model/addmodel.hpp"
#endif

namespace satap {
	class AddBloc : public Bloc, public AddModel {
	public:
		AddBloc(State::Context context);
		AddBloc(State::Context context, BlockCompositeModel* &firstOperand, BlockCompositeModel* &secondOperand);
		AddBloc(State::Context context, const BinaryModel& binaryModel);
	};
}
#endif
