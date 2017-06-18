#ifndef EVENTHANDLERS_HPP
#define EVENTHANDLERS_HPP
#include<thread>
#include "sfml.hpp"
#include "WindowHandler.hpp"
#include<iostream>

namespace crook{namespace events{namespace handlers{

class WindowEventHandler{
    private:
};

class KeyboardEventHandler{
    private:

    public:
       
        
};



class MouseEventHandler{
    private:
       crook::Window *cwin;
       sf::RenderWindow *window;

    public:
        MouseEventHandler * setContext(crook::Window *window){
            this->window = window->getHandle();
            this->cwin = window;
            return this;
        }
        void listen(){
            std::thread([](crook::Window *cwin,
            crook::events::handlers::MouseEventHandler *me,
            sf::RenderWindow *window
            ){
                sf::Event event;
                while(window->isOpen()){
                    while(window->pollEvent(event)){
                        if (event.type == sf::Event::Closed){
                            cwin->_windowEvents.onClose(crook::events::objects::WindowEventObject{20});
                            window->close();
                        }
                        if(event.type == sf::Event::MouseMoved){
                            cwin->_mouseEvents.onMouseMove(crook::events::objects::MouseEventObject{
                                window->getPosition().x,
                                window->getPosition().y,
                                event.mouseMove.x,
                                event.mouseMove.y
                                });
                        }
                        //onfocus
                        if(event.type == sf::Event::GainedFocus){
                            cwin->_windowEvents.onFoucs(crook::events::objects::WindowEventObject{
                                window->getSize().x,
                                window->getSize().y,
                                window->getPosition().x,
                                window->getPosition().y,
                            });
                        }
                    }
                }
                std::cout << "detached";
                delete me;

            },this->cwin,this,this->window).detach();
        }
};


}}}

#endif

/*


                    while (window->pollEvent(event))
                    {
                        //onclose
                        if (event.type == sf::Event::Closed){
                            this->_windowEvents.onClose(crook::events::objects::WindowEventObject{20});
                            window->close();
                        }
                        //mousemove
                        if(event.type == sf::Event::MouseMoved){
                            this->_mouseEvents.onMouseMove(crook::events::objects::MouseEventObject{
                                window->getPosition().x,
                                window->getPosition().y,
                                event.mouseMove.x,
                                event.mouseMove.y
                                });
                        }
                        //onfocus
                        if(event.type == sf::Event::GainedFocus){
                            this->_windowEvents.onFoucs(crook::events::objects::WindowEventObject{
                                window->getSize().x,
                                window->getSize().y,
                                window->getPosition().x,
                                window->getPosition().y,
                            });
                        }
                    }
*/