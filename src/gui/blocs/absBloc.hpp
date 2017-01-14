#ifndef ABS_BLOC_HPP
#define ABS_BLOC_HPP

#include "Bloc.hpp"
#include "model/absmodel.hpp"

/*
 *
 * Description :
 *
 *
*/


namespace satap {
	class AbsBloc : public Bloc, public AbsModel {
	public:
		AbsBloc(State::Context context);
		AbsBloc(State::Context context, BlockCompositeModel* Operand);
	};
}

#endif	// ABS_BLOC_HPP
