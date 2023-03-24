#ifndef MACROS_HPP_INCLUDED
#define MACROS_HPP_INCLUDED

///standards macros
#define _USE_MATH_DEFINES //constants defined in <cmath>

#ifdef DBG
///Debug configuration

#include <iostream>
#include <vector>

#define minLogPriority 0
//0 - steps per frame
//1 - position of the View
//2 - position of Starship
//3 - orbital position of Astres

#define log(x, priority) { if (priority <= minLogPriority) {std::cout << x << std::endl;} }

class Count{
public:
    static int counter;
};

inline int getCount() {return Count::counter;}
inline void count() { Count::counter++; }
inline void resetCount() { Count::counter = 0; }

#else

///Other config

#define log(x, y) {}
#define count() {}
#define getCount() {}
#define resetCount() {}

#endif

#endif // MACROS_HPP_INCLUDED
