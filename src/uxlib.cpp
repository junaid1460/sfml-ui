#include<vector>
#include "./uxlib.hpp"

std::vector<std::thread *> window_thread_handles;
std::vector<crook::Window *> windows;
crook::Window* createWindow(std::string title,int width,int height){
    auto t = new crook::Window(title,width,height);
   
    windows.push_back(t);
    return  t;
}

