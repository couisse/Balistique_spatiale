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

    //configuring the view
    m_view.reset(sf::FloatRect(0, 0, WIN_MODE.width, WIN_MODE.height));
    this->setView(m_view);
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

        log("Number of steps:", 0) //debugging stuff
        log(getCount(), 0);
        resetCount();
        log("---------------", 0);
    }
}

void Viewer::manageEvents(){
    //winfow events
    sf::Event event;
    while (this->pollEvent(event)){
        if (event.type==sf::Event::Closed){
            this->close();
        }
    }

    //moving the view
    sf::Vector2f offset(0,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        offset.y = -10;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        offset.y = 10;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        offset.x = -10;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        offset.x = 10;
    }
    m_view.setCenter(m_view.getCenter() + offset);
    this->setView(m_view);

    log("View position:", 1);
    log(m_view.getCenter().x, 1);
    log(m_view.getCenter().y, 1);
}

void Viewer::callPhysics(){
    Movement resulting = m_engine.step();
    sf::Vector2f point_1 = project(resulting.start);
    sf::Vector2f point_2 = project(resulting.stop);
    this->newVertice(point_1);
    this->newVertice(point_2);

    log("Starship position:", 2);
    log(point_1.x, 2);
    log(point_1.y, 2);

    count();
}


void Viewer::newVertice(sf::Vector2f pos){
    m_verticesTraj[current_vertice].position = pos;

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
