#ifndef TRAJECTORY_VERTICES_HPP_INCLUDED
#define TRAJECTORY_VERTICES_HPP_INCLUDED

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../utils/macros.hpp"
#include "../utils/consts.hpp"
#include "../utils/vector.hpp"
#include "../utils/sharedRessource.hpp"

class VisualTrajectory{
protected:
    SharedRessource<sf::VertexArray> m_vertices;
    size_t m_currentIdx;
    size_t m_previous;
    sf::Color m_color;

    bool increaseIdx();

public:
    VisualTrajectory(sf::Color color);
    ~VisualTrajectory();

    inline SharedRessource<sf::VertexArray>& getVertices() {return m_vertices;}

    void addPoint(Coords position);

};

#endif // TRAJECTORY_VERTICES_HPP_INCLUDED
