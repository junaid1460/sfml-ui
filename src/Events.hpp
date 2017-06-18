#ifndef EVENTS_HPP
#define EVENTS_HPP
#include<future>
#include "EventObjects.hpp"
namespace crook{
namespace events{
    class WindowEvents{
        static void (*_default)(crook::events::objects::WindowEventObject);
        public:
        std::function<void(crook::events::objects::WindowEventObject)> onClose = this->_default ;
        std::function<void(crook::events::objects::WindowEventObject)> onResize = this->_default ;
        std::function<void(crook::events::objects::WindowEventObject)> onRepositionStart = this->_default ;
        std::function<void(crook::events::objects::WindowEventObject)> onRepositionEnd = this->_default ;

        std::function<void(crook::events::objects::WindowEventObject)> onFoucs = this->_default ;
        
    };
     void (*WindowEvents::_default)(crook::events::objects::WindowEventObject) = [](crook::events::objects::WindowEventObject){};
    class MouseEvents{
           static void (*_default)(crook::events::objects::MouseEventObject);
        public:
        std::function<void(crook::events::objects::MouseEventObject)> onClick = this->_default ;
        std::function<void(crook::events::objects::MouseEventObject)> onMouseDown = this->_default;
        std::function<void(crook::events::objects::MouseEventObject)> onMouseUp  = this->_default;
        std::function<void(crook::events::objects::MouseEventObject)> onMouseMove = this->_default ;
    };
   void (*MouseEvents::_default)(crook::events::objects::MouseEventObject) = [](crook::events::objects::MouseEventObject){};

    class KeyEvents{
             static void (*_default)(crook::events::objects::KeyEventObject);
        public:
        std::function<void(crook::events::objects::KeyEventObject)> onKeyType = this->_default ;
        std::function<void(crook::events::objects::KeyEventObject)> onKeyDown = this->_default ;
        std::function<void(crook::events::objects::KeyEventObject)> onKeyUp = this->_default ;
    };
   void (*KeyEvents::_default)(crook::events::objects::KeyEventObject) = [](crook::events::objects::KeyEventObject){};

}}


#endif