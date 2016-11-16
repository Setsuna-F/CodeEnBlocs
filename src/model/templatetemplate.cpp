#include "templatetemplate.hpp"
#include "template.hpp"

TemplateTemplate::TemplateTemplate() :
	Template() {
	//do nothing because life is empty and you are part of it
}

TemplateTemplate::TemplateTemplate(int foo) {
	_foo = foo;
}

int getFoo() {
	return 0;
}

int doThings(int foo, int fooBar) {
	return foo;
}

