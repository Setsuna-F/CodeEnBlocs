#include "templatetemplate.hpp"
#include "template.hpp"

using namespace satap;

TemplateTemplate::TemplateTemplate() :
	Template() {
	//do nothing because life is empty and you are part of it
}

TemplateTemplate::TemplateTemplate(int foo) {
	_foo = foo;
}

int TemplateTemplate::getFoo() {
	return 0;
}

int TemplateTemplate::doThings(int foo, int fooBar) {
	return foo;
}
