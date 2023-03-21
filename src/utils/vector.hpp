#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <cmath>

#include <SFML/System.hpp>

#include "consts.hpp"


//those typedef lets mutate easily the dimensions of the space.
//To change the base, you also need to change below functions to match
//the new space you are considering

typedef sf::Vector2<double> Coords;
extern const Coords NullCoords;

struct Movement{
    Coords start;
    Coords stop;
};

inline double dot(const Coords& a, const Coords& b){
    return a.x * b.x + a.y * b.y;
}

inline double lenght(const Coords& source){
    return sqrt(dot(source, source));
}

inline Coords normalize(const Coords& source){
    return source/lenght(source);
}

inline Coords direction(const Coords& source, const Coords target){
    return normalize(target-source);
}

inline sf::Vector2f project(Coords source){
    return sf::Vector2f(source.x * rescaling, source.y*rescaling);
}


#endif // VECTOR_HPP_INCLUDED
