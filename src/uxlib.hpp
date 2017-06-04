#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>
#include<thread>
#include<future>
namespace crook{
    class WindowEventObject{
        public:
            unsigned int width;
            unsigned int height;
            int windowX;
            int windowY;
    };
    
    class KeyEventObject{
        public:
            wchar_t keyChar;cd src
            int x;
            int y;
    };

    class MouseEventObject{
        public:
        int windowX;
        int windowY;
        int x;
        int y;
    };

    class WindowEvents{
        static void (*_default)(crook::WindowEventObject);
        public:
        std::function<void(crook::WindowEventObject)> onClose = this->_default ;
        std::function<void(crook::WindowEventObject)> onResize = this->_default ;
        std::function<void(crook::WindowEventObject)> onRepositionStart = this->_default ;
        std::function<void(crook::WindowEventObject)> onRepositionEnd = this->_default ;

        std::function<void(crook::WindowEventObject)> onFoucs = this->_default ;
        
    };
     void (*WindowEvents::_default)(WindowEventObject) = [](WindowEventObject){};
    class MouseEvents{
           static void (*_default)(crook::MouseEventObject);
        public:
        std::function<void(crook::MouseEventObject)> onClick = this->_default ;
        std::function<void(crook::MouseEventObject)> onMouseDown = this->_default;
        std::function<void(crook::MouseEventObject)> onMouseUp  = this->_default;
        std::function<void(crook::MouseEventObject)> onMouseMove = this->_default ;
    };
   void (*MouseEvents::_default)(MouseEventObject) = [](MouseEventObject){};

    class KeyEvents{
             static void (*_default)(crook::KeyEventObject);
        public:
        std::function<void(crook::KeyEventObject)> onKeyType = this->_default ;
        std::function<void(crook::KeyEventObject)> onKeyDown = this->_default ;
        std::function<void(crook::KeyEventObject)> onKeyUp = this->_default ;
    };
   void (*KeyEvents::_default)(crook::KeyEventObject) = [](KeyEventObject){};
    
   
    class Window {

        private:
            sf::RenderWindow *window;
            std::string title;
            void _init(){
                window->setVerticalSyncEnabled(true);
            }
            crook::MouseEvents _mouseEvents;
            crook::KeyEvents _keyEvents;
            crook::WindowEvents _windowEvents;
            sf::Event event;
            bool _drawOnFocus = true;
        public:
            Window(std::string title){
                window = new sf::RenderWindow(sf::VideoMode(800,600),title,sf::Style::None);
                this->_init();
            }
            Window(std::string title,int width,int height){
                window = new sf::RenderWindow(sf::VideoMode(width,height),title,sf::Style::None);
                this->_init();
            }
            
            bool render(){
                
                if (window->isOpen())
                {
                
                    while (window->pollEvent(event))
                    {
                        //onclose
                        if (event.type == sf::Event::Closed){
                            this->_windowEvents.onClose(crook::WindowEventObject{20});
                            window->close();
                        }
                        //mousemove
                        if(event.type == sf::Event::MouseMoved){
                            this->_mouseEvents.onMouseMove(MouseEventObject{
                                window->getPosition().x,
                                window->getPosition().y,
                                event.mouseMove.x,
                                event.mouseMove.y
                                });
                        }
                        //onfocus
                        if(event.type == sf::Event::GainedFocus){
                            this->_windowEvents.onFoucs(WindowEventObject{
                                window->getSize().x,
                                window->getSize().y,
                                window->getPosition().x,
                                window->getPosition().y,
                            });
                        }
                    }
                    static sf::Color bg = sf::Color(250,250,250);
                    window->clear(bg);
                   
                    window->setActive();
                    window->display();
                    window->setActive(false);
                    return true;
                }
                return false;

            }
            ~Window(){
                delete window;
            }
            void mouseEvents(crook::MouseEvents t){
                this->_mouseEvents = t;
            }
            void keyEvents(crook::KeyEvents t){
                this->_keyEvents = t;
            }
            void windowEvents(crook::WindowEvents t){
                this->_windowEvents = t;
            }
    };
}