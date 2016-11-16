#include<iostream>

int main(int argc, char**argv){

   	#ifdef _WIN32
	  	std::cout << "Windows" << std::endl;
	#elif __APPLE__
		std::cout << "Apple" << std::endl;
	#elif __linux__
		std::cout << "Linux" << std::endl;
	#else
	#   error "Unknown compiler"
	#endif

	return 0;
}

