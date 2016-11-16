#include<iostream>

int main(int argc, char**argv){

   	#ifdef _WIN32
	  	std::cout << "Windows" << std::endl;
	#elif __APPLE__
		std::cout << "Apple" << std::endl;
		//#include "TargetConditionals.h"
		#if TARGET_IPHONE_SIMULATOR
		     std::cout << "iOS simulator" << std::endl;
		#elif TARGET_OS_IPHONE
		    std::cout << "iOS device" << std::endl;
		#elif TARGET_OS_MAC
		    std::cout << "Mac OS" << std::endl;
		#else
		#   error "Unknown Apple platform"
		#endif
	#elif __linux__
		std::cout << "Linux" << std::endl;
	#elif defined(_POSIX_VERSION)
		std::cout << "Posix" << std::endl;
	#else
	#   error "Unknown compiler"
	#endif

	return 0;
}

