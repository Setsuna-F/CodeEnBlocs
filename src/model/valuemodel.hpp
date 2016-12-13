#ifndef VALUEMODEL_HPP
#define VALUEMODEL_HPP

#include <iostream>
#include <string>
#include "blockcompositemodel.hpp"
#include "tools.h"

namespace satap{

	class ValueModel : public BlockCompositeModel{

		public:

			ValueModel();
			ValueModel(int value);
			ValueModel(double value);
			ValueModel(bool value);
			ValueModel(sct_type value);

			void setValue(sct_type n);
			sct_type getValue();

			sct_type execute();

		private:
			sct_type _value;
	};

}

#endif
