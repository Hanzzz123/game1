//
// Created by aanzs on 07/07/2023.
//

#include "State.h"



State::State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys) {
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}

State::~State() {

}

const bool & State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->quit = true;
    }
}

