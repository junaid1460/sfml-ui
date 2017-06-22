#include<vector>
#include "Component.cpp"
#include "./WindowHandler.cpp"
#include <string>
#include<functional>
#include "EventObjects.hpp"

std::vector<crook::Window *> windows;
crook::ui::Component* createWindow(std::string title,int width,int height){
    auto t = new crook::Window(title,width,height);
   
    windows.push_back(t);
    return  t;
}

void addEventListener(
            crook::ui::Component * component,
            const std::string eventname,
            const std::function<void(crook::events::objects::EventObject)> func
        ){
            component->addEventListener(eventname,func);
        }

