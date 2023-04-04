#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "../physics/phy_engine.hpp"
#include "trajectory_vertices.hpp"

/** \brief Displayer of the app
 */

class Viewer: public sf::RenderWindow {

public:
    Viewer(PhysicsEngine* engine);
    ~Viewer();

    /** \brief Main loop of the rendering
    */
    void play();


    VisualTrajectory* newTrajectory();
    void clearTrajectories();

protected:

    ///Internal methods
    /** \brief calls for all rendering-related method and display the frame
    */
    void rendering();

    /** \brief processes the events pile
    */
    void manageEvents();


    ///attributes
    sf::Clock m_clock;
    std::vector<VisualTrajectory> m_trajectories;
    sf::VertexArray m_verticesAstres;
    size_t current_vertice;
    sf::View m_view;
    PhysicsEngine* m_refEngine;

};

#endif // GAME_HPP_INCLUDED
