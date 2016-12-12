#ifndef ASSIGNMENTMODEL_HPP
#define ASSIGNMENTMODEL_HPP
#include "operatormodel.hpp"
#include "variablemodel.hpp"


namespace satap {

	class AssignmentModel : public OperatorModel {

		public:
			AssignmentModel();
			AssignmentModel(VariableModel variable, BlockCompositeModel & block);
			~AssignmentModel();
			VariableModel getVariable();
			BlockCompositeModel * getBlock();
			sct_type execute();

		private:
			//
			VariableModel _variable;

			//
			BlockCompositeModel * _block;
	};
}

#endif	// ASSIGNMENTMODEL_HPP
