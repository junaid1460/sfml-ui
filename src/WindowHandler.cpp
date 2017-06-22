#include "WindowHandler.hpp"
#include "EventHandlers.hpp"
#include "EventObjects.hpp"
#include <iostream>

sf::RenderWindow * crook::Window::getHandle(){
    return this->window;
}
crook::Window::Window(std::string title){
    window = new sf::RenderWindow(sf::VideoMode(800,600),title,sf::Style::None);
    this->_init();
}
crook::Window::Window(std::string title,int width,int height){
    window = new sf::RenderWindow(sf::VideoMode(width,height),title);
    this->_init();
}
void crook::Window::_init(){
                window->setFramerateLimit(1);
                (new crook::events::handlers::MouseEventHandler())
                ->setContext(this)
                ->listen();
                
            }

bool crook::Window::render(){
    
    if (window->isOpen())
    {
    
        static sf::Color bg = sf::Color(250,250,250);
        window->clear(bg);
        window->setActive();
        window->display();
        window->setActive(false);
        return true;
    }
    return false;

}
crook::Window::~Window(){
    delete window;
}
