#include "templatetemplatemodel.hpp"
#include "templatemodel.hpp"

using namespace satap;

TemplateTemplateModel::TemplateTemplateModel() :
	Template() {
	//do nothing because life is empty and you are part of it
}

TemplateTemplateModel::TemplateTemplateModel(int foo) {
	_foo = foo;
}

int TemplateTemplateModel::getFoo() {
	return 0;
}

int TemplateTemplateModel::doThings(int foo, int fooBar) {
	return foo;
}
