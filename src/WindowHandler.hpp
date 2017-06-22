#ifndef WINDOWHANDLER_HPP
#define WINDOWHANDLER_HPP


#include "Component.cpp"

#include "sfml.hpp"

#include<string>
#include<thread>
#include<future>
namespace crook{

    class Window :public crook::ui::Component {

        private:
            sf::RenderWindow *window;
            std::string title;
      
            sf::Event event;
            bool _drawOnFocus = true;
            void _init();
        public:
            
            sf::RenderWindow * getHandle();
            Window(std::string title);
            Window(std::string title,int width,int height);
            bool render();
            ~Window();
    };
}



#endif