#ifndef MULTLEVELMODEL_HPP
#define MULTLEVELMODEL_HPP

#include "levelmodel.hpp"

namespace satap {
	class MultLevelModel : public LevelModel{
		public:
			MultLevelModel();
			void reset();
	};
}

#endif
