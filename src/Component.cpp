#ifndef COMPONENT_CPP
#define COMPONENT_CPP

#include<functional>
#include<map>
#include<string>
#include "Events.hpp"
namespace crook{
    namespace ui{
class Component{
        typedef std::pair<std::string,std::pair<int,int>> entry;
        #define _mouse crook::events::MouseEvents::EventList
        typedef std::pair<int,int> event;
        const static struct{
             enum {
                mouse = 0,
                key = 1,
                win = 2
            };
        } _cat;
        typedef std::map<std::string,std::pair<int,int>> eventstringmap;
        eventstringmap events = {
            entry{"mouseclick",event{_cat.mouse,_mouse.click}},
            entry{"mouseup",event{_cat.mouse,_mouse.up}},
            entry{"click",event{_cat.mouse,_mouse.click}},
            entry{"mousemove",event{_cat.mouse,_mouse.move}},
        };

    public:
            crook::events::MouseEvents _mouseEvents;
            crook::events::KeyBoardEvents _keyEvents;
            crook::events::WindowEvents _windowEvents;

            void addEventListener(const std::string fn,std::function<void(crook::events::objects::EventObject)> func){
                eventstringmap::iterator it = events.find(fn);
                if(it != events.end()){
                    //{"name",{x,y}}
                    switch(it->second.first){
                        case 0://mouse
                            this->_mouseEvents.eventCatList[it->second.second].
                            push_back(func);
                        break;
                        case 1://key
                            this->_keyEvents.eventCatList[it->second.second].
                            push_back(func);
                        break;
                        case 2://window
                            this->_windowEvents.eventCatList[it->second.second].
                            push_back(func);
                        break;

                        
                    }
                }
            }
};
}
}
#endif