#ifndef ABSMODEL_HPP
#define ABSMODEL_HPP
#include "unarymodel.hpp"

/*
 *
 * Description :
 *
 *
*/

namespace satap {

	class AbsModel : public UnaryModel {

		public:
			AbsModel();
			AbsModel(BlockCompositeModel* operand);
			AbsModel(const UnaryModel & unaryModel);
			~AbsModel();
		
			/*Methodes*/
			sct_type execute();
	};
}

#endif	// ABSMODEL_HPP
