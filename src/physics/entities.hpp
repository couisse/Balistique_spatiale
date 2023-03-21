#ifndef ENTITIES_HPP_INCLUDED
#define ENTITIES_HPP_INCLUDED

#include "../utils/vector.hpp"

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


class Astre: public Entity {

public:
    Astre() {}
    Astre(double weight, Coords pos): Entity(weight, pos) {}
};


class StarShip: public Entity{
protected:
    Coords m_speed;

public:
    StarShip() {}
    StarShip(double weight, Coords pos, Coords speed): Entity(weight, pos), m_speed(speed) {}
    virtual inline const Coords getSpeed() const {return m_speed;}
    virtual inline void setSpeed(Coords speed) {m_speed = speed;}
    virtual void move(Coords acceleration);
};

#endif // ENTITIES_HPP_INCLUDED
