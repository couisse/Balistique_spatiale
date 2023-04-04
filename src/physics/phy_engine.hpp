#ifndef PHY_ENGINE_HPP_INCLUDED
#define PHY_ENGINE_HPP_INCLUDED

#include "../files/files_interaction.hpp"
#include "entities.hpp"
#include "ship_commands.hpp"
#include "../render/trajectory_vertices.hpp"

enum PhyException {Crash};

class PhysicsEngine {

protected:
    //real attributes
    SharedRessource<std::vector<Astre>> m_astres;
    StarShip m_ship;
    //relative to current simulation
    ShipCommands* m_shipCommands;
    VisualTrajectory* m_buffer;
    size_t m_stepBufferCounter;
    double m_time;

    //internal physics calculations
    Coords gravityAcceleration(const Astre* puller);
    void moveShip();
    void moveAstres();

public:

    PhysicsEngine();
    ~PhysicsEngine();

    Coords simulate(ShipCommands* commands, VisualTrajectory* target);

    //access to Astres array
    inline SharedRessource<std::vector<Astre>>& getAstres() {return m_astres;}
    //access to StarShip
    inline StarShip* getStarship() {return &m_ship;}
};

#endif // PHY_ENGINE_HPP_INCLUDED
