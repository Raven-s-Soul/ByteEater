#pragma once
#include <iostream>

// 	Debug Macro
//	1 - Active , 0 - Deactive
#define DEBUG_LOG 1
#define Convert 1
#define DeConvert 1

#if DEBUG_LOG
#define LOG(message) std::cout << message << std::endl;
#else
#define LOG(message)
#endif