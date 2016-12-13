#include "outputmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

OutputModel::OutputModel() {
	//
}

OutputModel::~OutputModel() {
	//
}

sct_type OutputModel::execute() {
	//mettre l'output dans la liste des outputs
	
	return _valOutput;
}

typeBloc OutputModel::getType() {
	return OutputBlocType;
}