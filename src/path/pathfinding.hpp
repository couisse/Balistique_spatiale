#ifndef PATHFINDING_HPP_INCLUDED
#define PATHFINDING_HPP_INCLUDED

#include <deque>
#include "../physics/phy_engine.hpp"
#include "../render/window.hpp"

/** \brief This class holds the pathfinding algorithm of the program
 */

class PathFinder{

protected:
    PhysicsEngine* m_engineRef;
    Viewer* m_windowRef;
    ShipCommands m_command;

public:
    PathFinder(PhysicsEngine* engine, Viewer* window);

    /** \brief Launches the algorithm of pathfinding with current settings
     * (that are loaded by the Physical Engine)
     *
     *  \return a ShipCommand object, describing a path that should correspond to the path to calculate
     */
    ShipCommands* findPath();
};

#endif // PATHFINDING_HPP_INCLUDED
