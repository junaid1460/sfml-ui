#include "./uxlib.cpp"
#include "./chai.hpp"
#include "Events.hpp"
#include "EventObjects.hpp"

#ifdef __UNIX__
CHAISCRIPT_MODULE_EXPORT 
#endif

chaiscript::ModulePtr uxLibrary(){

    chaiscript::ModulePtr m(new chaiscript::Module());
    m->add(chaiscript::fun(&createWindow),"createWindow");


    //MouseEvent registration
    chaiscript::utility::add_class<crook::events::objects::MouseEventObject>(*m,
        "MouseEventObject",
        {},
        {
        {chaiscript::fun(&crook::events::objects::MouseEventObject::x), "x"},
       {chaiscript::fun(&crook::events::objects::MouseEventObject::y), "y"}
        });


    chaiscript::utility::add_class<crook::events::MouseEvents>(*m,
        "MouseEvents",
        {chaiscript::constructor<crook::events::MouseEvents()>()},
        {
        {chaiscript::fun(&crook::events::MouseEvents::onClick), "onClick"},
        {chaiscript::fun(&crook::events::MouseEvents::onMouseDown), "onMouseDown"},
        {chaiscript::fun(&crook::events::MouseEvents::onMouseUp), "onMouseUp"},
        {chaiscript::fun(&crook::events::MouseEvents::onMouseMove), "onMouseMove"}
    });

    //window functions
    chaiscript::utility::add_class<crook::Window>(*m,
        "Window",{},
        {
        {chaiscript::fun(&crook::Window::mouseEvents), "mouseEvents"},
        {chaiscript::fun(&crook::Window::keyEvents), "keyEvents"},
        {chaiscript::fun(&crook::Window::windowEvents), "windowEvents"}
     });

     //keyboard Event registration
     chaiscript::utility::add_class<crook::events::KeyEvents>(*m,
        "KeyEvents",{chaiscript::constructor<crook::events::KeyEvents()>()},
        {
        {chaiscript::fun(&crook::events::KeyEvents::onKeyDown), "onKeyDown"},
        {chaiscript::fun(&crook::events::KeyEvents::onKeyUp), "onKeyUp"},
        {chaiscript::fun(&crook::events::KeyEvents::onKeyType), "onKeyType"}
     });

     //window events
     chaiscript::utility::add_class<crook::events::WindowEvents>(*m,
        "WindowEvents",{chaiscript::constructor<crook::events::WindowEvents()>()},
        {
        {chaiscript::fun(&crook::events::WindowEvents::onClose), "onClose"},
        {chaiscript::fun(&crook::events::WindowEvents::onRepositionEnd), "onRepositionEnd"},
        {chaiscript::fun(&crook::events::WindowEvents::onRepositionStart), "onRepostionStart"},
        {chaiscript::fun(&crook::events::WindowEvents::onResize), "onResize"},
        {chaiscript::fun(&crook::events::WindowEvents::onFoucs), "onFocus"}
     });
      chaiscript::utility::add_class<crook::events::objects::WindowEventObject>(*m,
        "WindowEventObject",
        {},
        {
        {chaiscript::fun(&crook::events::objects::WindowEventObject::height), "height"},
        {chaiscript::fun(&crook::events::objects::WindowEventObject::width), "width"},
        {chaiscript::fun(&crook::events::objects::WindowEventObject::windowX), "windowX"},
        {chaiscript::fun(&crook::events::objects::WindowEventObject::windowY), "windowY"}
        });
    return m;
}


void render(std::string file){
   chaiscript::ChaiScript script;

    script.add(uxLibrary());
    script.eval_file(file);
    bool r = false;
    do{
        r= false;
        for(auto i:windows){
            r|=i->render();
        }
    }while(r);
}