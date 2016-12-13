#include "valuemodel.hpp"

using namespace satap;

ValueModel::ValueModel(){}

ValueModel::ValueModel(int value){
	_value.int_type = &value;
	_value.double_type = nullptr;
	_value.bool_type = nullptr;
}

ValueModel::ValueModel(double value){
	_value.int_type = nullptr;
	_value.double_type = &value;
	_value.bool_type = nullptr;
}

ValueModel::ValueModel(bool value){
	_value.int_type = nullptr;
	_value.double_type = nullptr;
	_value.bool_type = &value;
}

ValueModel::ValueModel(sct_type value): _value(value){}

void ValueModel::setValue(sct_type value){
	_value = value;
}

sct_type ValueModel::getValue(){
	return _value;
}

sct_type ValueModel::execute(){
	return _value;
}
