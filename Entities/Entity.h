//
// Created by aanzs on 25/07/2023.
//

#ifndef GAME1_ENTITY_H
#define GAME1_ENTITY_H

#include <vector>
#include "iostream"
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity {
private:

protected:
    sf::CircleShape shape;
    float movementSpeed;
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;


public:
    Entity();
    virtual ~Entity();

    //Functions
    virtual void move(const float &dt, const float x, const float y);
    virtual void collision();
    virtual void shoot();

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};


#endif //GAME1_ENTITY_H
