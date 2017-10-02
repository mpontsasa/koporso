#include<iostream>
#include"ScreenObject.h"
#include "utility.h"

class CollisionHandler{

    CollisionHandler(){};
    std::vector<ScreenObject*> collidableObjects;
public:
   static CollisionHandler& access();
   void checkCollision(ScreenObject* otherObject, Direction _direction, sf::Vector3i& newPoint);
};
