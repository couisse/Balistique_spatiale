#include "application.hpp"

Application::Application(): m_engine(), m_viewer(&m_engine), m_finder(&m_engine, &m_viewer), m_renderingThread(&Viewer::play, &m_viewer){
    Random::init();
}

Application::~Application(){
}

void Application::play(){
    m_renderingThread.launch();
    m_finder.findPath();
    m_renderingThread.wait();
}
