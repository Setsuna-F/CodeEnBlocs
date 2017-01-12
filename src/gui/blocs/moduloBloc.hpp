#ifndef MODULO_BLOC_HPP
#define MODULO_BLOC_HPP

#include "Bloc.hpp"
#include "model/modulomodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {
	class ModuloBloc : public Bloc, public ModuloModel {
	public:
		ModuloBloc(State::Context context);
		ModuloBloc(State::Context context, BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
		ModuloBloc(State::Context context, const BinaryModel& binaryModel);
	};
}

#endif	// MODULO_BLOC_HPP
