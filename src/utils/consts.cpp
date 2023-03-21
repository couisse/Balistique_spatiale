#include "consts.hpp"

///Window managment
const sf::VideoMode WIN_MODE(600,600);
const sf::Time TIME_PER_FRAME = sf::milliseconds(33);
size_t MAX_VERTICES = 500000;

///Physics




const double G = 6.674 * pow(10, -17); //Newton's universal gravity constant
const double dt = 5; //resolution in time of the simulation

double rescaling = 0.5 * pow(10, -3);
