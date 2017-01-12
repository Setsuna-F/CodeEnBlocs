#ifndef MULT_BLOC_HPP
#define MULT_BLOC_HPP

#include "Bloc.hpp"
#include "model/multmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {
	class MultBloc : public Bloc, public MultModel {
	public:
		MultBloc(State::Context context);
		MultBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
		MultBloc(State::Context context, const BinaryModel& binaryModel);
	};
}

#endif	// MULT_BLOC_HPP
