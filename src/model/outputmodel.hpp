#ifndef OUTPUTMODEL_HPP
#define OUTPUTMODEL_HPP
#include "blocksimplemodel.hpp"
#include "outputlistmodel.hpp"
#include "tools.h"

/*
 *
 * Description :
 *
 *
*/

namespace satap {


	class OutputModel : public BlockSimpleModel {

		public:
			OutputModel();
			~OutputModel();
			sct_type execute();

		private:
			sct_type _valOutput;

	};
}

#endif	// OUTPUTMODEL_HPP
