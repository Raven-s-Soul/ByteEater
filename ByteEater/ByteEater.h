#pragma once

#include <iostream>

// Debug Macro
//#define DEBUG
#ifndef DEBUG
	#define LOG(message) std::cout << message << std::endl;
#else
	#define LOG(message)
#endif