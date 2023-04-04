#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "../render/window.hpp"
#include "../path/pathfinding.hpp"
#include "../utils/random.hpp"

/** \brief Main class of the application
 *  Stores major objects like the GUI, the Physical engine...
 *  Handles multithreading
 */

class Application{

public:

    /** \brief The constructor also initialize all the environment of execution
     */
    Application();

    ~Application();

    /** \brief Main loop of the app
    *   No arguments, no return. Should not raise exception
    */
    void play();

protected:

    //generics
    sf::Clock m_clock;
    //physics
    PhysicsEngine m_engine;
    //rendering
    Viewer m_viewer;
    //pathfinding
    PathFinder m_finder;
    //threading
    sf::Thread m_renderingThread;

};

#endif // APPLICATION_HPP_INCLUDED
