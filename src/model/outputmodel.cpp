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
	_valOutput.int_type		=nullptr;
	_valOutput.double_type	=nullptr;
	_valOutput.bool_type	=nullptr;
}

OutputModel::~OutputModel() {
	//
}

sct_type OutputModel::execute() {
	std::string val = "";
	if (_valOutput.int_type){
		val = typeToString(_valOutput.int_type);
		std::cout << "DANS INT :" << std::endl;
	}
	else if (_valOutput.double_type){
		val = typeToString(_valOutput.double_type);
		std::cout << "DANS DOUBLE :" << std::endl;
	}
	else if (_valOutput.bool_type ){
		val = (*_valOutput.bool_type?"true":"false");
		std::cout << "DANS BOOL :" << std::endl;
	}

	std::cout << "Output :" << val << std::endl;
	_outPutList->push(val);
	return _valOutput;
}

void OutputModel::setValue(sct_type v)
{
	_valOutput = v;
}

/*typeBloc OutputModel::getType() {
	return OutputBlocType;
}*/
