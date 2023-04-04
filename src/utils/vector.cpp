#include "vector.hpp"

const Coords NullCoords(0,0);

void generateOrientations(double magnitude, double perArc, std::vector<Coords>& container){
    double angle = 360. / perArc;
    double current = 0;
    Coords vect;
    for (double i = 0; i < perArc; i++){
        vect.x = cos(current) * magnitude;
        vect.y = -sin(current) * magnitude;
        container.push_back(vect);
        current += angle;
    }
}
