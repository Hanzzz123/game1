//
// Created by aanzs on 07/07/2023.
//

#ifndef GAME1_STATE_H
#define GAME1_STATE_H

#include "..\Entities\Entity.h"

class State {
private:

protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;

    //Resources
    std::vector<sf::Texture> textures;

    //functions
    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;

    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};


#endif //GAME1_STATE_H
