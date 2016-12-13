#ifndef ADD_BLOC_HPP
#define ADD_BLOC_HPP

#include "Bloc.hpp"
#include "model/addmodel.hpp"

namespace satap {
	class AddBloc : public Bloc, public AddModel {
	public:
		AddBloc(State::Context context);
		AddBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
		AddBloc(State::Context context, const BinaryModel& binaryModel);
	};
}
#endif
