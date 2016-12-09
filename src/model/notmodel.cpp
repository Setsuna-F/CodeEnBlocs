#include "notmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

NotModel::NotModel() {
	//
}

NotModel::NotModel(BlockCompositeModel* operand) : UnaryModel(operand) {
	//
}

NotModel::NotModel(const UnaryModel & unaryModel) : UnaryModel(unaryModel) {
	//
}

NotModel::~NotModel() {
	//
}

sct_type NotModel::execute() {
	/*int operand = std::stoi( this->UnaryModel::getOperand()->execute() );
	
	return std::to_string(!operand);*/
	
	sct_type res;
	return res;
}
