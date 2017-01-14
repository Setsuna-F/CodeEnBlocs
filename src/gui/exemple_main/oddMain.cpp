#include "oddMain.hpp"

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

	std::cout <<"----------- odd main 1 ----------- "<< std::endl;
	int opi_1 		= 10;
	double opd_1 	= 21.11f;
	bool vbool 		= true;

	sct_type var_1;
		var_1.int_type	= &opi_1;
		var_1.double_type = nullptr;
		var_1.bool_type	= &vbool;

	// le Constructeur de Context ?????
    State::Context context;
	VariableBloc vbloc(context, "v1", var_1);

	std::cout << "------------- parité de int -------------- " << std::endl;
	// à la place de l'argument context : j'ai juste mis null
	OddBloc odd_instance_1 (context, &vbloc, &vbloc_2);
	std::cout << "Resulat de la parité de " << opi_1 << " est : " << *odd_instance_1.execute().bool_type << std::endl;

	std::cout << "------------- parité de double -------------- " << std::endl;
	//modification des variables pour les donner des float
	var_1.int_type	= &opi_1;
	var_1.double_type = nullptr;
	var_1.bool_type	= &vbool;
	vbloc.setValue(var_1);

	OddBloc odd_instance_2 (context, &vbloc, &vbloc_2);
	std::cout << "Resulat de la parité de " << opi_1 << " est : " << *odd_instance_2.execute().bool_type  << std::endl;

}
