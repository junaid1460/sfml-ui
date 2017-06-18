#include<vector>
#include "./WindowHandler.cpp"

std::vector<crook::Window *> windows;
crook::Window* createWindow(std::string title,int width,int height){
    auto t = new crook::Window(title,width,height);
   
    windows.push_back(t);
    return  t;
}

