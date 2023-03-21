#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../utils/macros.hpp"
#include "../utils/random.hpp"
#include "../physics/phy_engine.hpp"

/** \brief Main class of the app
 */

class Viewer: public sf::RenderWindow {

public:
    Viewer();
    ~Viewer();
    /** \brief Main loop of the app
    */
    void play();

protected:

    ///Internal methods
    /** \brief calls for all rendering-related method and display the frame
    */
    void rendering();

    /** \brief processes the events pile
    */
    void manageEvents();

    void callPhysics();

    void newVertice(sf::Vector2f pos);


    ///attributes
    sf::Clock m_clock;
    Physics_engine m_engine;
    sf::VertexArray m_verticesTraj;
    sf::VertexArray m_verticesAstres;
    size_t current_vertice;

};

#endif // GAME_HPP_INCLUDED
