#pragma once

#ifndef NDEBUG
#define PRINT(x) do { std::cerr << x; } while (0)

#else
#define PRINT(X) do {} while (0)
#endif