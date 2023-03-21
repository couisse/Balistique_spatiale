#ifndef MACROS_HPP_INCLUDED
#define MACROS_HPP_INCLUDED



#ifdef DBG
///Debug configuration

#include <iostream>
#include <vector>

#define log(x) {std::cout << x << std::endl;}

class Count{
public:
    static int counter;
};

inline int getCount() {return Count::counter;}
inline void count() { Count::counter++; }
inline void resetCount() { Count::counter = 0; }

#else

///Other config

#define log(x) {}
#define count() {}
#define getCount() {}
#define resetCount() {}

#endif

#endif // MACROS_HPP_INCLUDED
