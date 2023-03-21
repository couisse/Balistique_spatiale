#include "window.hpp"

Viewer::Viewer(){
    this->create(WIN_MODE, "Balistique spatiale");
    Random::init();

    //configuring the space for all trajectory vertices
    m_verticesTraj.resize(MAX_VERTICES);
    for (size_t i =0; i< MAX_VERTICES; i++){
        m_verticesTraj[i].color = sf::Color::Green;
    }
    m_verticesTraj.setPrimitiveType(sf::Lines);
    current_vertice = 0;

    //configuring the space for all astres vertices
    size_t astres_number = m_engine.getAstres()->size();
    m_verticesAstres.resize(astres_number * 4);
    for (size_t i = 0; i< astres_number * 4; i++){
        m_verticesAstres[i].color = sf::Color::Blue;
    }
    m_verticesAstres.setPrimitiveType(sf::Quads);
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

    count();
}


void Viewer::newVertice(sf::Vector2f pos){
    m_verticesTraj[current_vertice].position = pos;

    sf::Vertex current = m_verticesTraj[current_vertice];
    current_vertice++;
    if (current_vertice>=MAX_VERTICES){
        current_vertice = 0;
    }
}

void Viewer::rendering(){
    //getting where astres are

    size_t astres_number = m_engine.getAstres()->size();
    size_t current = 0;
    sf::Vector2f projection;
    for (size_t i = 0; i< astres_number; i++){
        projection = project(m_engine.getAstres()->at(i).getPosition());
        m_verticesAstres[current].position = projection + sf::Vector2f(-10, 0);
        m_verticesAstres[current+1].position = projection + sf::Vector2f(0, -10);
        m_verticesAstres[current+2].position = projection + sf::Vector2f(10, 0);
        m_verticesAstres[current+3].position = projection + sf::Vector2f(0, 10);
        current += 4;
    }

    //real rendering stuff
    this->clear(sf::Color::Black);
    this->draw(m_verticesTraj);
    this->draw(m_verticesAstres);
    this->display();
}
