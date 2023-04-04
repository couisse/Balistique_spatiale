#ifndef SHAREDRESSOURCE_HPP_INCLUDED
#define SHAREDRESSOURCE_HPP_INCLUDED

#include <SFML/System/Mutex.hpp>

template<class T>
class SharedRessource{
protected:
    sf::Mutex m_lock;
    T m_ressource;

public:
    SharedRessource(): m_ressource() {}
    SharedRessource(T value): m_ressource(value) {}
    SharedRessource(const SharedRessource<T> &source): m_ressource(source.protectedAccess()) {}

    inline void lock() {m_lock.lock();}
    inline void unlock() {m_lock.unlock();}
    inline const T& protectedAccess() const {return m_ressource;}
    inline T& access() {return m_ressource;}
};

#endif // SHAREDRESSOURCE_HPP_INCLUDED
