#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#include "utility.h"
#include <SFML/System/Vector3.hpp>

class Collidable
{
public:
    virtual bool collisionPoint (Collidable *col, sf::Vector3i point, Direction dir) = 0;    //if col would collide whit this if moved to point, return true and the point of collision in point. Otherwise return false

protected:

private:
};

#endif // COLLIDABLE_H
