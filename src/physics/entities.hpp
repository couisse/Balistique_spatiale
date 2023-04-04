#ifndef ENTITIES_HPP_INCLUDED
#define ENTITIES_HPP_INCLUDED

#include "trajectories.hpp"

/** \brief Generic Entity for the Physical Engine. Is only
 *  determinated by its mass and its position in space.
 */
class Entity {

protected:
    double m_weight;
    Coords m_position;

public:
    Entity() {}
    Entity(double weight, Coords pos): m_weight(weight), m_position(pos) {}
    virtual ~Entity() {}
    virtual inline const double getWeight() const {return m_weight;}
    virtual inline const Coords getPosition() const {return m_position;}
    virtual inline void setPosition(Coords pos) {m_position = pos;}
};

/** \brief Hold the data of an Astre. Uses an Orbit object to calculate
 *  position over time.
 */
class Astre: public Entity {
protected:
    Orbit m_orbit;
    double m_sqDeathRange;

public:
    Astre() {}
    Astre(double weight, Coords pos, double deathRange, Orbit path): Entity(weight, pos), m_orbit(path), m_sqDeathRange(deathRange*deathRange) {}
    inline void orbit(double time) {m_position = m_orbit.calculatePosition(time);}
    inline const double getSquaredDeathRange() const {return m_sqDeathRange;}
};

/** \brief Hold the data of a Starship. That include the current speed of the ship.
 */
class StarShip: public Entity{
protected:
    Coords m_speed;

public:

    static std::vector<Coords> shipThrusts;

    StarShip() {}
    StarShip(double weight, Coords pos, Coords speed): Entity(weight, pos), m_speed(speed) {}
    virtual inline const Coords getSpeed() const {return m_speed;}
    virtual inline void setSpeed(Coords speed) {m_speed = speed;}
    virtual void move(Coords acceleration);
};

#endif // ENTITIES_HPP_INCLUDED
