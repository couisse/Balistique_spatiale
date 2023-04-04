#include "pathfinding.hpp"

PathFinder::PathFinder(PhysicsEngine* engine, Viewer* window): m_command(sf::Vector2<double>(0, pow(10, 7)), NullCoords){
    m_engineRef = engine;
    m_windowRef = window;
}

ShipCommands* PathFinder::findPath(){
    m_command.setPosition(m_engineRef->getStarship()->getPosition());
    try{
        m_engineRef->simulate(&m_command, m_windowRef->newTrajectory());
    }catch (const PhyException e){
        switch (e){
        case Crash:
            log("Le vaisseau a crashe", -1);
            break;
        default:
            log("Une exception physique est survenue", -1);
        }
    }
    return &m_command;
}
