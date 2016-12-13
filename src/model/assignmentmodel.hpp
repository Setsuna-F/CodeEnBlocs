#ifndef ASSIGNMENTMODEL_HPP
#define ASSIGNMENTMODEL_HPP
#include "binarymodel.hpp"
#include "variablemodel.hpp"
#include "outputmodel.hpp"


namespace satap {

	class AssignmentModel : public BinaryModel {

		public:
			AssignmentModel();
			AssignmentModel(VariableModel* firstOperand, BlockCompositeModel* secondOperand);
			~AssignmentModel();
			BlockModel* getFirstOperand();
			void setFirstOperand(BlockModel* operand);
			sct_type execute();
			typeBloc getType();
		protected:
			BlockModel* _firstOperand;
	};
}

#endif	// ASSIGNMENTMODEL_HPP
