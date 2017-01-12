#ifndef DIV_BLOC_HPP
#define DIV_BLOC_HPP

#include "Bloc.hpp"
#include "model/divmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {
	class DivBloc : public Bloc, public DivModel {
	public:
		DivBloc(State::Context context);
		DivBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
		DivBloc(State::Context context, const BinaryModel& binaryModel);
	};
}

#endif	// DIV_BLOC_HPP
