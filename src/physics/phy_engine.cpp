#include "phy_engine.hpp"

PhysicsEngine::PhysicsEngine(){
    m_astres.lock();
    m_ship = uploadSettings("", &m_astres.access());
    m_astres.unlock();
    m_shipCommands = nullptr;
    m_buffer = nullptr;
    m_stepBufferCounter = 0;
}

PhysicsEngine::~PhysicsEngine(){
}

Coords PhysicsEngine::simulate(ShipCommands *commands, VisualTrajectory *target){
    //initializing
    if (commands == nullptr) {return NullCoords;}
    m_time = commands->getTimeRange().x;
    m_shipCommands = commands;
    m_ship.setPosition(commands->getStartPosition());
    m_buffer = target;

    //looping the simulation
    while (m_time < commands->getTimeRange().y){
        this->moveAstres();
        this->moveShip();
        m_time += dt;
    }

    //sending final result
    return m_ship.getPosition();
}

void PhysicsEngine::moveShip(){

    Coords acceleration = m_shipCommands->getThrust(m_time);


    m_astres.lock();
    for (size_t i = 0; i<m_astres.access().size(); i++){
        acceleration += this->gravityAcceleration(&m_astres.access()[i]);
    }
    m_astres.unlock();

    //applying acceleration and speed
    m_ship.move(acceleration);

    //getting new position
    if (m_stepBufferCounter >= STEPS_PER_LINE && m_buffer != nullptr){
        m_buffer->addPoint(m_ship.getPosition());
        m_stepBufferCounter = 0;
    }else{
        m_stepBufferCounter++;
    }

    log("Position of Starship", 2);
    log(m_ship.getPosition().x, 2);
    log(m_ship.getPosition().y, 2);

}

void PhysicsEngine::moveAstres(){
    m_astres.lock();
    for (size_t i = 0; i<m_astres.access().size(); i++){
        m_astres.access()[i].orbit(m_time);
    }
    m_astres.unlock();
}


Coords PhysicsEngine::gravityAcceleration(const Astre* puller){
    //newton's formula for gravity strength is F = GMm/R²
    //since we are directly using the Second Law, we can simplify by m:  a = GM/R²

    Coords offset = puller->getPosition() - m_ship.getPosition(); //the direction of the pulling
    double sqDistance = dot(offset, offset); //the relative distance squared
    if (sqDistance < puller->getSquaredDeathRange()){
        m_astres.unlock(); //unlocks the astre array (will cause a deadlock if not)
        throw Crash;
    }
    offset /= (sqrt(sqDistance) * sqDistance); //normalizing the vector and applying the division by R²
    offset *= G * puller->getWeight(); //finish the formula

    return offset;
}
