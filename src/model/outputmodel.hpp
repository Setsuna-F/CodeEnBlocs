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
			OutputModel(OutputListModel* outPutList);
			~OutputModel();
			sct_type execute();
			typeBloc getType();
			void setValue(sct_type v);

		private:
			OutputListModel* _outPutList;
			sct_type _valOutput;

	};
}

#endif	// OUTPUTMODEL_HPP
