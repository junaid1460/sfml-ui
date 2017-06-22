#ifndef EVENTS_HPP
#define EVENTS_HPP
#include<functional>
#include<vector>
#include<array>
#include "EventObjects.hpp"
namespace crook{
namespace events{
// class WindowEvents{
//     static void (*_default)(crook::events::objects::WindowEventObject);
//     public:
//     std::function<void(crook::events::objects::WindowEventObject)> onClose = this->_default ;
//     std::function<void(crook::events::objects::WindowEventObject)> onResize = this->_default ;
//     std::function<void(crook::events::objects::WindowEventObject)> onRepositionStart = this->_default ;
//     std::function<void(crook::events::objects::WindowEventObject)> onRepositionEnd = this->_default ;

//     std::function<void(crook::events::objects::WindowEventObject)> onFoucs = this->_default ;
    
// };
//  void (*WindowEvents::_default)(crook::events::objects::WindowEventObject) = [](crook::events::objects::WindowEventObject){};
//     class MouseEvents{
//            static void (*_default)(crook::events::objects::MouseEventObject);
//            std::vector<std::function<void(crook::events::objects::MouseEventObject)> _onclick;
//         public:
//         std::function<void(crook::events::objects::MouseEventObject)> onClick = this->_default ;
//         std::function<void(crook::events::objects::MouseEventObject)> onMouseDown = this->_default;
//         std::function<void(crook::events::objects::MouseEventObject)> onMouseUp  = this->_default;
//         std::function<void(crook::events::objects::MouseEventObject)> onMouseMove = this->_default ;
//     };
//    void (*MouseEvents::_default)(crook::events::objects::MouseEventObject) = [](crook::events::objects::MouseEventObject){};

//     class KeyEvents{
//              static void (*_default)(crook::events::objects::KeyEventObject);
//         public:
//         std::function<void(crook::events::objects::KeyEventObject)> onKeyType = this->_default ;
//         std::function<void(crook::events::objects::KeyEventObject)> onKeyDown = this->_default ;
//         std::function<void(crook::events::objects::KeyEventObject)> onKeyUp = this->_default ;
//     };
//    void (*KeyEvents::_default)(crook::events::objects::KeyEventObject) = [](crook::events::objects::KeyEventObject){};
    class Events{

    };

   class WindowEvents:public Events{
    typedef std::vector<std::function<void(crook::events::objects::WindowEventObject)>> Fucntions;       
    public:
        std::array<Fucntions,4/*number of events*/> eventCatList;
        static const struct{
         enum{
            close = 0, /*eventcatlist indexes*/
            reposition_start = 1,
            resposition_end = 2,
            resize  = 3
        } ;
        }  EventList;
        //abstraction for event firing
        void onEvent(crook::events::objects::WindowEventObject data,int type){
            Fucntions::iterator it = eventCatList[type].begin();
            while(it != eventCatList[type].end()){
               (*it)(data);
               ++it;
            }
        }
   };


   class KeyBoardEvents:public Events{
    
    typedef std::vector<std::function<void(crook::events::objects::KeyEventObject)>> Fucntions;       
    public:
        std::array<Fucntions,3/*number of events*/> eventCatList;
        static const struct{
         enum{
            type = 0,
            down = 1,
            up = 2
        } ;
        }  EventList;
        //abstraction for event firing
        void onEvent(crook::events::objects::KeyEventObject data,int type){
            Fucntions::iterator it = eventCatList[type].begin();
            while(it != eventCatList[type].end()){
               (*it)(data);
               ++it;
            }
        }
   };

   class MouseEvents:public Events{
    typedef std::vector<std::function<void(crook::events::objects::MouseEventObject)>> Fucntions;       
    public:
        std::array<Fucntions,4/*number of events*/> eventCatList;
        static const struct{
         enum{
            click = 0, /*eventcatlist indexes*/
            down = 1,
            up = 2,
            move  = 3
        } ;
        }  EventList;
        
        //abstraction for event firing
        void onEvent(crook::events::objects::MouseEventObject data,int type){
            Fucntions::iterator it = eventCatList[type].begin();
            while(it != eventCatList[type].end()){
               (*it)(data);
               ++it;
            }
        }
   };

}}


#endif