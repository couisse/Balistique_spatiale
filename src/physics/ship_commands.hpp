#ifndef SHIP_COMMANDS_HPP_INCLUDED
#define SHIP_COMMANDS_HPP_INCLUDED

class ShipCommands{
protected:
    sf::Vector2<double> m_timeRange;
    Coords m_startPosition;

public:
    ShipCommands(sf::Vector2<double> timeRange, Coords start): m_timeRange(timeRange), m_startPosition(start) {}
    virtual ~ShipCommands(){}
    virtual inline const sf::Vector2<double> getTimeRange() const {return m_timeRange;}
    virtual inline const Coords getStartPosition() const {return m_startPosition;}
    virtual inline void setPosition(Coords position) {m_startPosition = position;}
    virtual const Coords getThrust(double t) const {return NullCoords;}
};

#endif // SHIP_COMMANDS_HPP_INCLUDED
