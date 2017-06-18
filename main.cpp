#include<string>
#include "src/EventHandlers.hpp"
#include <X11/Xlib.h>
extern void render(std::string file);

int main(int argc,char **argv)
{
    XInitThreads();
    render("./main.chai");
    return 0;
}