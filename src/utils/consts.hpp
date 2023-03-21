#ifndef CONSTS_HPP_INCLUDED
#define CONSTS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

///Window managment
extern const sf::VideoMode WIN_MODE;
extern const sf::Time TIME_PER_FRAME;
extern size_t MAX_VERTICES;

///Physics

/** \brief Standard Units: tons / s / km
 */


extern const double G; //Newton's universal gravity constant
extern const double dt; //resolution in time of the simulation

extern double rescaling;


#endif // CONSTS_HPP_INCLUDED
