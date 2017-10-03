#ifndef WALLBLOCK_H
#define WALLBLOCK_H
#include "utility.h"

class WallBlock : public Collidable
{
public:
    WallBlock();
    ~WallBlock();
    bool collisionPoint (Collidable *col, sf::Vector3i point, Direction dir);

protected:
    Direction dir;  // direction of the wall

};
#endif // WALLBLOCK_H
