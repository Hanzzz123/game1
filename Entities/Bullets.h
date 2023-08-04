//
// Created by aanzs on 04/08/2023.
//

#ifndef GAME1_BULLETS_H
#define GAME1_BULLETS_H

#include "Entity.h"

class Bullets {
private:

protected:


public:
    Bullets();
    sf::CircleShape shape;
    sf::Vector2f currVelocity;
    float maxSpeed;
};


#endif //GAME1_BULLETS_H
