#include "moduloMain.hpp"

/*
 *
 * Description :
 *
 *
*/

using namespace satap;

int main (int argc, char ** argv) {
	example();
	return 0;
}

void example() {

	std::cout <<"----------- modulo main 1 ----------- "<< std::endl;
	int opi_1 		= 10;
	int opi_2 		= 20;
	bool vbool 		= true;

	sct_type var_1;
		var_1.int_type	= &opi_1;
		var_1.double_type = nullptr;
		var_1.bool_type	= &vbool;

	sct_type var_2;
		var_2.int_type	= &opi_2;
		var_2.double_type = nullptr;
		var_2.bool_type	= nullptr;

	// le Constructeur de Context ?????
    State::Context context;
	VariableBloc vbloc_1(context, "v1", var_1);
	VariableBloc vbloc_2(context, "v2", var_2);

	std::cout << "------------- modulo de int -------------- " << std::endl;
	// à la place de l'argument context : j'ai juste mis null
	ModuloBloc modulo_instance_1 (context, &vbloc_1, &vbloc_2);
	std::cout << "Resulat de " << opi_1 << " - " << opi_2 << " = " << *modulo_instance_1.execute().int_type << std::endl;

}
