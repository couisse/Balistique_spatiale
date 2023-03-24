#ifndef PHY_ENGINE_HPP_INCLUDED
#define PHY_ENGINE_HPP_INCLUDED

#include "../files/files_interaction.hpp"
#include "entities.hpp"

class Physics_engine {

protected:
    std::vector<Astre> m_astres;
    StarShip m_ship;
    size_t m_time;

    //internal physics calculations
    Coords gravityAcceleration(const Astre* puller);
    Movement stepShip();
    void stepAstres();


public:
    Physics_engine();
    ~Physics_engine();

    Movement step();

    //access to Astres array
    inline std::vector<Astre>* getAstres() {return &m_astres;}
};

#endif // PHY_ENGINE_HPP_INCLUDED
