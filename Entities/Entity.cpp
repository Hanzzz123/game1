//
// Created by aanzs on 25/07/2023.
//

#include "Entity.h"

Entity::Entity() {
    this->shape.setRadius(25.f);
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 0.5f;
}

Entity::~Entity() {

}

void Entity::move(const float &dt,const float dir_x, const float dir_y) {
    this->shape.move(dir_x * movementSpeed * dt,dir_y * movementSpeed * dt);
}

//screen collision
void Entity::collision() {
    //Left collision
    if(this->shape.getPosition().x < 0.f){
        this->shape.setPosition(0,this->shape.getPosition().y);
    }
    //Top collision
    if(this->shape.getPosition().y < 0.f){
        this->shape.setPosition(this->shape.getPosition().x,0);
    }
    //Right collision
    if(this->shape.getPosition().x + this->shape.getGlobalBounds().width > 800) {
        this->shape.setPosition(800 - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
    }
    //Left collision
    if(this->shape.getPosition().y + this->shape.getGlobalBounds().height > 600){
        this->shape.setPosition(this->shape.getPosition().x, 600 - this->shape.getGlobalBounds().height);
    }
}

void Entity::update(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->move(dt, -1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->move(dt, 1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->move(dt, 0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->move(dt, 0.f, 1.f);
    }
}


void Entity::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}