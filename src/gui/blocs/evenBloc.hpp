#ifndef EVEN_BLOC_HPP
#define EVEN_BLOC_HPP

#include "Bloc.hpp"
#include "model/evenmodel.hpp"

/*
 *
 * Description :
 *
 *
*/


namespace satap {
	class EvenBloc : public Bloc, public EvenModel {
	public:
		EvenBloc(State::Context context);
		EvenBloc(State::Context context, BlockCompositeModel* Operand);
	};
}

#endif	// EVEN_BLOC_HPP
