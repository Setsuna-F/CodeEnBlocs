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
			OutputModel():_outPutList(nullptr){
				_valOutput.int_type		=nullptr;
				_valOutput.double_type	=nullptr;
				_valOutput.bool_type	=nullptr;
			}
			OutputModel(OutputListModel* outPutList);
			~OutputModel();

			//void setOutputListModel(OutputListModel* & bsm){_outPutList = bsm;}

			sct_type execute();
			//typeBloc getType();
			void setValue(sct_type v);

		private:
			OutputListModel* _outPutList;
			sct_type _valOutput;

	};
}

#endif	// OUTPUTMODEL_HPP
