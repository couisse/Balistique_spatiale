#ifndef UPLOAD_HPP_INCLUDED
#define UPLOAD_HPP_INCLUDED

#include <vector>
#include <string>

#include "../physics/entities.hpp"

/** \brief Go extract system data for the pathfinding. Creates all Astre.
 *
 * \param filename: the name of data file
 * \param target: a pointer to Astre buffer. Will emplace all Astres in place in this buffer
 * \return A StarShip object, containing the start position and speed of the ship.
 */
StarShip uploadSettings(std::string filename, std::vector<Astre>* target);

#endif // UPLOAD_HPP_INCLUDED
