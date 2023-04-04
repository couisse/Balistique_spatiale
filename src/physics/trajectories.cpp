#include "trajectories.hpp"

Orbit::Orbit(Coords center, double radius, double realSpeed, double initialAngle){
    m_center = center;
    m_radius = radius;
    m_arcSpeed = (radius == 0) ? 0 : (realSpeed/radius);
    m_initial = initialAngle;
}

Coords Orbit::calculatePosition(double time){
    if (m_radius == 0) {return m_center;}

    double angle = m_arcSpeed * time + m_initial;
    Coords pos(m_center.x + cos(angle) * m_radius, m_center.y - sin(angle) * m_radius);

    log("Orbital path:", 3);
    log(pos.x, 3);
    log(pos.y, 3);

    return pos;
}
