#ifndef EVENTHANDLERS_HPP
#define EVENTHANDLERS_HPP
#include<thread>
#include "sfml.hpp"
#include "WindowHandler.hpp"
#include<iostream>

namespace crook{namespace events{namespace handlers{





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

            std::thread([](crook::ui::Component *cwin,
            crook::events::handlers::MouseEventHandler *me,
            sf::RenderWindow *window
            ){
                sf::Event event;
                while(window->waitEvent(event)){
                    if (event.type == sf::Event::Closed){
                            cwin->_windowEvents.onEvent(crook::events::objects::WindowEventObject{20,23},
                            crook::events::WindowEvents::EventList.close
                            );
                            window->close();
                        }
                    else
                    (std::thread(me->fireEvent,event,window,cwin)).detach();
                    
                }
                std::cout << "detached";
                delete me;

            },this->cwin,this,this->window).detach();
        }

        static void  fireEvent(sf::Event event,sf::RenderWindow *window,crook::ui::Component *cwin){
            
                        if(event.type == sf::Event::MouseMoved){
                            cwin->_mouseEvents.onEvent(crook::events::objects::MouseEventObject{
                                window->getPosition().x,
                                window->getPosition().y,
                                event.mouseMove.x,
                                event.mouseMove.y
                                },
                                crook::events::MouseEvents::EventList.move
                                );
                        }
                        else if(event.type == sf::Event::EventType::){
                            cwin->_mouseEvents.onEvent(crook::events::objects::MouseEventObject{
                                window->getPosition().x,
                                window->getPosition().y,
                                event.mouseMove.x,
                                event.mouseMove.y
                                },
                                crook::events::MouseEvents::EventList.move
                                );
                        }
                        //onfocus
                       
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