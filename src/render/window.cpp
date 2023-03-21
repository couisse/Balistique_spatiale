#include "window.hpp"

Viewer::Viewer(){
    this->create(WIN_MODE, "Balistique spatiale");
    Random::init();
    m_array.resize(MAX_VERTICES); //allocating the space for all vertices
    for (size_t i =0; i< MAX_VERTICES; i++){
        m_array[i].color = sf::Color::Green;
    }
    m_array.setPrimitiveType(sf::Lines);
    current_vertice = 0;
}

Viewer::~Viewer(){
}

void Viewer::play(){
    sf::Time time;
    while (this->isOpen()){
        m_clock.restart();

        this->manageEvents();
        this->rendering();

        while (m_clock.getElapsedTime() < TIME_PER_FRAME){
            this->callPhysics();
        }
        log(getCount()); //debugging stuff
        resetCount();
        log("---------------");
    }
}

void Viewer::manageEvents(){
    sf::Event event;
    while (this->pollEvent(event)){
        if (event.type==sf::Event::Closed){
            this->close();
        }
    }
}

void Viewer::callPhysics(){
    Movement resulting = m_engine.step();
    sf::Vector2f point_1 = project(resulting.start);
    sf::Vector2f point_2 = project(resulting.stop);
    this->newVertice(point_1);
    this->newVertice(point_2);

    log(point_1.x);
    log(point_1.y);
    log("");
    count();
}


void Viewer::newVertice(sf::Vector2f pos){
    m_array[current_vertice].position = pos;
    current_vertice++;
    if (current_vertice>MAX_VERTICES){
        current_vertice = 0;
    }
}

void Viewer::rendering(){
    this->clear(sf::Color::Black);
    this->draw(m_array);
    this->display();
}
