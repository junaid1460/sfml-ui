#ifndef EVENTOBJECTS_HPP
#define EVENTOBJECTS_HPP
namespace crook{namespace events{namespace objects{
    class EventObject{

    };

    class WindowEventObject :public EventObject{
        public:
            WindowEventObject(unsigned int w =0,unsigned int h =0,int x=0,int y=0){
                this->width = w;
                this->height = h;
                this->windowX = x;
                this->windowY = y;
            }
            unsigned int width;
            unsigned int height;
            int windowX;
            int windowY;
    };
    
    class KeyEventObject :public EventObject{
        public:
            KeyEventObject(wchar_t c ,int x = 0,int y = 0){
                this->keyChar = c;
                this->x = x;
                this->y = y;
            }
            wchar_t keyChar;
            int x;
            int y;
    };

    class MouseEventObject :public EventObject{
        public:
        MouseEventObject(int wx = 0,int wy = 0,int x = 0,int y = 0){
            this->windowX = wx;
            this->windowY = wy;
            this->x = x;
            this->y = y;
        }
        int windowX;
        int windowY;
        int x;
        int y;


    };

}}}
#endif