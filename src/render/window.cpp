#include "window.hpp"

Viewer::Viewer(PhysicsEngine* engine){

    m_refEngine = engine;

    //configuring the space for all astres vertices
    m_refEngine->getAstres().lock();
    size_t astres_number = m_refEngine->getAstres().access().size();
    m_refEngine->getAstres().unlock();

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
    this->create(WIN_MODE, "Balistique spatiale");
    while (this->isOpen()){
        m_clock.restart();
        log("Calling a frame", 3);

        this->manageEvents();
        this->rendering();

        sf::sleep(TIME_PER_FRAME-m_clock.getElapsedTime());
    }
}

void Viewer::manageEvents(){
    //winfow events
    sf::Event event;
    while (this->pollEvent(event)){
        if (event.type==sf::Event::Closed){
            this->close();
        }else if (event.type == sf::Event::Resized){
            m_view.setSize(sf::Vector2f(event.size.width, event.size.height));
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
}


VisualTrajectory* Viewer::newTrajectory(){
    m_trajectories.emplace_back(sf::Color::Green);
    return &m_trajectories[m_trajectories.size()-1];
}

void Viewer::clearTrajectories(){
    for (size_t i = 0; i < m_trajectories.size(); i++){
        m_trajectories[i].getVertices().lock(); //locking everyone to make sure it is no more used
    }
    m_trajectories.clear();
}

void Viewer::rendering(){
    //getting where astres are

    m_refEngine->getAstres().lock();

    size_t astres_number = m_refEngine->getAstres().access().size();
    size_t current = 0;
    sf::Vector2f projection;
    for (size_t i = 0; i< astres_number; i++){
        projection = project(m_refEngine->getAstres().access()[i].getPosition());
        m_verticesAstres[current].position = projection + sf::Vector2f(-10, 0);
        m_verticesAstres[current+1].position = projection + sf::Vector2f(0, -10);
        m_verticesAstres[current+2].position = projection + sf::Vector2f(10, 0);
        m_verticesAstres[current+3].position = projection + sf::Vector2f(0, 10);
        current += 4;
    }


    m_refEngine->getAstres().unlock();

    //real rendering stuff
    this->clear(sf::Color::Black);

    this->draw(m_verticesAstres);

    for (size_t i = 0; i < m_trajectories.size(); i++){
        m_trajectories[i].getVertices().lock();
        this->draw(m_trajectories[i].getVertices().access());
        m_trajectories[i].getVertices().unlock();
    }
    this->display();
}
