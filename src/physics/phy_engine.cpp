#include "phy_engine.hpp"

Physics_engine::Physics_engine(){
    m_ship = StarShip(7.*pow(10, 19), Coords(0, 3.8*pow(10,5)), Coords(0, 1));
    m_astres.emplace_back( 5.972 * pow(10,24), Coords(3.8*pow(10,5), 3.8*pow(10,5)) );
}

Physics_engine::~Physics_engine(){
}

Movement Physics_engine::step(){
    Movement ship_travel;
    //getting last position
    ship_travel.start = m_ship.getPosition();

    Coords acceleration = NullCoords;

    for (size_t i = 0; i<m_astres.size(); i++){
        acceleration += this->gravityAcceleration(&m_astres[i]);
    }

    //applying acceleration and speed
    m_ship.move(acceleration);

    //getting new position
    ship_travel.stop = m_ship.getPosition();

    return ship_travel;
}


Coords Physics_engine::gravityAcceleration(const Astre* puller){
    //newton's formula for gravity strength is F = GMm/R²
    //since we are directly using the Second Law, we can simplify by m:  a = GM/R²

    Coords offset = puller->getPosition() - m_ship.getPosition(); //the direction of the pulling
    double sqDistance = dot(offset, offset); //the relative distance squared
    offset /= (sqrt(sqDistance) * sqDistance); //normalizing the vector and applying the division by R²
    offset *= G * puller->getWeight(); //finish the formula

    return offset;
}
