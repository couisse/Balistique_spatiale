#include "trajectory_vertices.hpp"

VisualTrajectory::VisualTrajectory(sf::Color color){

    m_vertices.lock();
    m_vertices.access().resize(MAX_VERTICES);
    m_vertices.access().setPrimitiveType(sf::LinesStrip);
    m_vertices.unlock();

    m_color = color;
    m_previous = 0;
    m_currentIdx = 1;
}

VisualTrajectory::~VisualTrajectory(){
}

bool VisualTrajectory::increaseIdx(){
    m_currentIdx++;
    if (m_currentIdx>=MAX_VERTICES){
        m_currentIdx = 0;
        return true;
    }
    return false;
}

void VisualTrajectory::addPoint(Coords position){
    m_vertices.lock();
    sf::Vector2f projection = project(position);

    do {
        m_vertices.access()[m_previous].color = m_color;
        m_vertices.access()[m_previous].position = projection;
        m_vertices.access()[m_currentIdx].position = projection;
        m_previous = m_currentIdx;
    }while (this->increaseIdx()); //doing it a second time to connect end and begin point
    m_vertices.access()[m_currentIdx].color = sf::Color(0,0,0,0);

    m_vertices.unlock();
}
