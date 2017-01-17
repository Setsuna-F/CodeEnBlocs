#include "assignmentmodel.hpp"

using namespace satap;

AssignmentModel::AssignmentModel() {
	//
}
/*
 *
 *
 */
AssignmentModel::AssignmentModel(BlockModel* firstOperand, BlockCompositeModel* secondOperand)	:
	BinaryModel(firstOperand, secondOperand) { }

AssignmentModel::~AssignmentModel() {
	//
}

/*BlockModel * satap::AssignmentModel::getFirstOperand() {
	return _firstOperand;
}

void satap::AssignmentModel::setFirstOperand(BlockModel * operand) {
	_firstOperand = operand;
}*/

sct_type AssignmentModel::execute() {
	sct_type value;
	value.int_type 		= nullptr;
	value.double_type 	= nullptr;
	value.bool_type 	= nullptr;

	if(_secondOperand){
		value = (_secondOperand)->execute();
	}
	else{
		//std::cout<< "ERREUR: PAS DE SECOND ARGUMENT : [FONCTION : " << __FUNCTION__ << "]" <<std::endl;
		value.int_type 		= nullptr;
		value.double_type 	= nullptr;
		value.bool_type 	= nullptr;
		return value;
	}

	if(!((value.int_type==nullptr)&&(value.double_type==nullptr)&&(value.bool_type==nullptr))){
		if (getFirstOperand()->getType() == OutputBlocType) {
			OutputModel* out = dynamic_cast<OutputModel*>(getFirstOperand());
			out->setValue(value);
			out->execute();
		}
		else if (getFirstOperand()->getType() == VariableBlocType) {
			VariableModel* var = dynamic_cast<VariableModel*>(getFirstOperand());
			var->setValue(value);
			var->execute();
		}
		else{
			//std::cout<< "ERREUR: " << __FUNCTION__ << std::endl;
		}
	}

	return value;
}

/*typeBloc AssignmentModel::getType() {
	return AssignementBlocType;
}
*/
int AssignmentModel::getNbElements() {
	if (_firstOperand == NULL && _secondOperand == NULL) {
		return 1;
	}
	else if (_firstOperand == NULL) {
		return 1 + _secondOperand->getNbElements();
	}
	else if (_secondOperand == NULL) {
		return 1 + _firstOperand->getNbElements();
	}
	else {
		int gauche = _firstOperand->getNbElements();
		int droite = _secondOperand->getNbElements();
		return 1 + gauche + droite;
	}
}
