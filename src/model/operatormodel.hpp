#ifndef OPERATORMODEL_HPP
#define OPERATORMODEL_HPP

#include "blockcompositemodel.hpp"
#include "tools.h"

namespace satap{

	class OperatorModel : public BlockCompositeModel{
		public :
			virtual sct_type execute() = 0;

	};

}

#endif
