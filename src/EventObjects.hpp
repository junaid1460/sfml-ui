#ifndef EVENTOBJECTS_HPP
#define EVENTOBJECTS_HPP
namespace crook{namespace events{namespace objects{


    class WindowEventObject{
        public:
            unsigned int width;
            unsigned int height;
            int windowX;
            int windowY;
    };
    
    class KeyEventObject{
        public:
            wchar_t keyChar;
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

}}}
#endif