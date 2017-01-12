#include "addMain.hpp"

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

	std::cout <<"----------- add main ----------- "<< std::endl;
	int opi_1 		= 10;
	int opi_2 		= 20;
	double opd_1 	= 21.11f;
	double opd_2 	= 12.22f;
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

	std::cout << "------------- addtion de int -------------- " << std::endl;

	AddBloc add_instance_1 (context, &vbloc_1, &vbloc_2);
	std::cout << "Resulat de " << opi_1 << " - " << opi_2 << " = " << *add_instance_1.execute().int_type << std::endl;

	std::cout << "------------- addition de double -------------- " << std::endl;
	//modification des variables pour les donner des float
	var_1.int_type	= nullptr;
	var_1.double_type = &opd_1;
	var_1.bool_type	= &vbool;
	vbloc_1.setValue(var_1);

	var_2.int_type	= nullptr;
	var_2.double_type = &opd_2;
	var_2.bool_type	= nullptr;
	vbloc_2.setValue(var_2);

	AddBloc add_instance_2 (context, &vbloc_1, &vbloc_2);
	std::cout << "Resulat de " << opd_1 << " - " << opd_2 << " = " << *add_instance_2.execute().double_type << std::endl;

}
