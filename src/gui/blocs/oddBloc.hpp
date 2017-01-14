#ifndef ODD_BLOC_HPP
#define ODD_BLOC_HPP

#include "Bloc.hpp"
#include "model/oddmodel.hpp"

/*
 *
 * Description :
 *
 *
*/


namespace satap {
	class OddBloc : public Bloc, public OddModel {
	public:
		OddBloc(State::Context context);
		OddBloc(State::Context context, BlockCompositeModel* Operand);
	};
}

#endif	// ODD_BLOC_HPP
