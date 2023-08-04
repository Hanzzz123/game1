#include "../headers/engine.h"

//static functions

//initializer functions
void Engine::initWindow() {
    //Creates a SFML window using options from a window.ini file

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";

    sf::VideoMode window_bounds(800,600);
    unsigned frame_rate_limit = 120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open()){
        std::getline(ifs,title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Game");
    this->window->setFramerateLimit(frame_rate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Engine::initKeys() {
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

}

void Engine::initStates() {
    this->states.push(new GameState(this->window,&this->supportedKeys));
}

//Constructors/Destructors
Engine::Engine() {
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Engine::~Engine(){
    delete this->window;
    while(this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}



//Functions
void Engine ::endApplicaton() {
    std::cout << "Ending Application!" <<"\n";
}

void Engine::updateDt() {
    //Updates the dt variable with the time it takes to render 1 frame
    this->dt = this->dtClock.getElapsedTime().asSeconds();
}

void Engine::updateSFMLEvents() {

    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }


}

void Engine::update() {
    this->updateSFMLEvents();
    if(!this->states.empty()){
        this->states.top()->update(this->dt);
        if(this->states.top()->getQuit()) {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //Applications end
    else {
        this->endApplicaton();
        this->window->close();
    }
}

void Engine::render() {
    this->window->clear();

    //render items
    if(!this->states.empty()){
        this->states.top()->render(this->window);
    }

    this->window->display();
}

void Engine::run() {
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}



