#include "files_interaction.hpp"

StarShip uploadSettings(std::string filename, std::vector<Astre>* target){

    generateOrientations(0.00981, 8, StarShip::shipThrusts);

    Orbit path(Coords(2*3.8*pow(10,5), 2*3.8*pow(10,5)), 0, 0, 0);
    target->emplace_back( 5.972 * pow(10,21), Coords(2*3.8*pow(10,5), 2.6*3.8*pow(10,5)), 6000, path);

    Orbit path2(Coords(2*3.8*pow(10,5), 2*3.8*pow(10,5)), 2*3.8*pow(10,5), 0.2, M_PI_2);

    target->emplace_back( 5 * pow(10,21), Coords(2*3.8*pow(10,5), 1.4*3.8*pow(10,5)), 6000, path2);

    return StarShip(7.*pow(10, 19), Coords(3.8*pow(10,5), 2*3.8*pow(10,5)), Coords(0, 1.31));
}
