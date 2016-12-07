#ifndef OPERATORMODEL_HPP
#define OPERATORMODEL_HPP

#include "blockcompositemodel.hpp"

namespace satap{

	class OperatorModel : public BlockCompositeModel{
		public :
			virtual std::string execute() = 0;
	};

}

#endif
