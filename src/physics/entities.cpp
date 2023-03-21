#include "entities.hpp"

void StarShip::move(Coords acceleration){
    m_speed += acceleration * dt;
    m_position += m_speed * dt;
}
