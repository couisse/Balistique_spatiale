#include "consts.hpp"

///Window managment
const sf::VideoMode WIN_MODE(300,300);
const sf::Time TIME_PER_FRAME = sf::milliseconds(33);
size_t MAX_VERTICES = 10000;

///Physics




const double G = 6.674 * pow(10, -17); //Newton's universal gravity constant
const double dt = 1; //resolution in time of the simulation

double rescaling = pow(10, -3);
