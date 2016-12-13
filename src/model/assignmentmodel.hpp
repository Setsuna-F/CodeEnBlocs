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
			void setVariable(VariableModel & variable);
			BlockCompositeModel * getBlock();
			void setPartieDroite(BlockCompositeModel & block);
			sct_type execute();
			typeBloc getType();
		private:
			//
			VariableModel _variable;

			//
			BlockCompositeModel * _block;
	};
}

#endif	// ASSIGNMENTMODEL_HPP
