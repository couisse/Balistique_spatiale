#ifndef PHY_ENGINE_HPP_INCLUDED
#define PHY_ENGINE_HPP_INCLUDED

#include <vector>

#include "entities.hpp"

class Physics_engine {

protected:
    std::vector<Astre> m_astres;
    StarShip m_ship;

    //internal physics calculations
    Coords gravityAcceleration(const Astre* puller);

public:
    Physics_engine();
    ~Physics_engine();

    Movement step();
};

#endif // PHY_ENGINE_HPP_INCLUDED
