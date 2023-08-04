//
// Created by aanzs on 04/08/2023.
//

#include "Bullets.h"
Bullets::Bullets(){
    this->shape.setRadius(5.f);
    this->shape.setFillColor(sf::Color::Red);
    this->currVelocity = sf::Vector2f(0.f,0.f);
    this->maxSpeed = (15.f);

};