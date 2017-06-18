#ifndef WINDOWHANDLER_HPP
#define WINDOWHANDLER_HPP


#include "sfml.hpp"

#include<string>
#include<thread>
#include<future>

#include "Events.hpp"
#include "EventObjects.hpp"
namespace crook{

    class Window {

        private:
            sf::RenderWindow *window;
            std::string title;
      
            sf::Event event;
            bool _drawOnFocus = true;
            void _init();
        public:
            crook::events::MouseEvents _mouseEvents;
            crook::events::KeyEvents _keyEvents;
            crook::events::WindowEvents _windowEvents;
            sf::RenderWindow * getHandle();
            Window(std::string title);
            Window(std::string title,int width,int height);
            bool render();
            ~Window();
            void mouseEvents(crook::events::MouseEvents t);
            void keyEvents(crook::events::KeyEvents t);
            void windowEvents(crook::events::WindowEvents t);
    };
}



#endif