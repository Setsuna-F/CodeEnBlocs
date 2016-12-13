#include "outputmodel.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

OutputModel::OutputModel(OutputListModel* outPutList) {
	_outPutList = outPutList;
}

OutputModel::~OutputModel() {
	//
}

sct_type OutputModel::execute() {
	std::string val = "";
	if (_valOutput.int_type)
		val = typeToString(_valOutput.int_type);
	else if (_valOutput.double_type)
		val = typeToString(_valOutput.double_type);
	else if (*_valOutput.bool_type == true)
		val = "true";
	else
		val = "false";
	_outPutList->push(val);
	return _valOutput;
}

void OutputModel::setValue(sct_type v)
{
	_valOutput = v;
}

typeBloc OutputModel::getType() {
	return OutputBlocType;
}