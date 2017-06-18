#ifndef COMPONENT_BUILT_IN_CPP
#define COMPONENT_BUILT_IN_CPP
#include "component.cpp"

namespace ui{
    namespace components{
        class Div:public ui::Component {
            int width;
            int height;
            public:
            override void render(const sf::RenderWindow &window){
                
            }
        };


    }
}

#endif