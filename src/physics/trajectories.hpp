#ifndef TRAJECTORIES_HPP_INCLUDED
#define TRAJECTORIES_HPP_INCLUDED

#include <cmath>

#include "../utils/vector.hpp"

class Orbit{
protected:
    Coords m_center;
    double m_radius;
    double m_arcSpeed;
    double m_initial;

public:
    Orbit(Coords center = NullCoords, double radius = 0, double realSpeed = 0, double initialAngle = 0);
    ~Orbit() {}
    Coords calculatePosition(size_t time);
};

#endif // TRAJECTORIES_HPP_INCLUDED
