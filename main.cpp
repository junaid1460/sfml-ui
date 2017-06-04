
#include<iostream>
#include<algorithm>
#include<vector>
#include<thread>
#include<future>
#ifdef __UNIX__
#include<X11/Xlib.h>
#endif

extern void render(std::string file);

int main(int argc,char **argv)
{
    #ifdef __UNIX__
    XInitThreads();
    #endif
    render("./main.chai");
    return EXIT_SUCCESS;
}