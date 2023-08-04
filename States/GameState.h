//
// Created by aanzs on 09/07/2023.
//

#ifndef GAME1_GAMESTATE_H
#define GAME1_GAMESTATE_H
#include "State.h"

class GameState :
public State {
private:
    Entity player;

    //Functions
    void initKeybinds();

public:
    GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys);
    virtual ~GameState();

    //Functions
    void endState();

    void updateInput(const float& dt);

    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};


#endif //GAME1_GAMESTATE_H
