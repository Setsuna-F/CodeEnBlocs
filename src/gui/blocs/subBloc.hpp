#ifndef SUB_BLOC_HPP
#define SUB_BLOC_HPP


#include "Bloc.hpp"
#include "model/submodel.hpp"


namespace satap {
	class SubBloc : public Bloc, public SubModel {
		public:
            SubBloc(State::Context context);
    		SubBloc(State::Context context, BlockCompositeModel* &firstOperand, BlockCompositeModel* &secondOperand);
    		SubBloc(State::Context context, const BinaryModel& binaryModel);
	};
}
#endif
