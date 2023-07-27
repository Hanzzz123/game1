// Created by aanzs on 03/07/2023.

#ifndef GAME1_ENGINE_H
#define GAME1_ENGINE_H

#include "../States/GameState.h"

using namespace sf;

class Engine{
private:

    //Variables
    sf::RenderWindow* window;
    sf::Event sfEvent;

    sf::Clock dtClock;

    //keep track for time to render
    float dt;

    std::stack<State*> states;
    std::map<std::string, int> supportedKeys;

    //Initialization
    void initWindow();
    void initKeys();
    void initStates();

public:

    //Constructors/Destructors
    Engine();
    ~Engine();

    //Functions

    //Regular
    void endApplicaton();

    //update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //Render
    void render();

    //Core
    void run();


};

#endif //GAME1_ENGINE_H
