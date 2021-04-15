#pragma once
#include <iostream>

#ifndef NDEBUG
#define LOG(x) do { std::cerr << x; } while (0)

#else
#define LOG(X) do {} while (0)
#endif