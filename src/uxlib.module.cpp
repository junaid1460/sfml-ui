#include "./uxlib.cpp"
#include "./chai.hpp"

#ifdef __UNIX__
CHAISCRIPT_MODULE_EXPORT 
#endif

chaiscript::ModulePtr uxLibrary(){

    chaiscript::ModulePtr m(new chaiscript::Module());
    m->add(chaiscript::fun(&createWindow),"createWindow");


    //MouseEvent registration
    chaiscript::utility::add_class<crook::MouseEventObject>(*m,
        "MouseEventObject",
        {},
        {
        {chaiscript::fun(&crook::MouseEventObject::x), "x"},
       {chaiscript::fun(&crook::MouseEventObject::y), "y"}
        });


    chaiscript::utility::add_class<crook::MouseEvents>(*m,
        "MouseEvents",
        {chaiscript::constructor<crook::MouseEvents()>()},
        {
        {chaiscript::fun(&crook::MouseEvents::onClick), "onClick"},
        {chaiscript::fun(&crook::MouseEvents::onMouseDown), "onMouseDown"},
        {chaiscript::fun(&crook::MouseEvents::onMouseUp), "onMouseUp"},
        {chaiscript::fun(&crook::MouseEvents::onMouseMove), "onMouseMove"}
    });

    //window functions
    chaiscript::utility::add_class<crook::MouseEvents>(*m,
        "Window",{},
        {
        {chaiscript::fun(&crook::Window::mouseEvents), "mouseEvents"},
        {chaiscript::fun(&crook::Window::keyEvents), "keyEvents"},
        {chaiscript::fun(&crook::Window::windowEvents), "windowEvents"}
     });

     //keyboard Event registration
     chaiscript::utility::add_class<crook::KeyEvents>(*m,
        "KeyEvents",{chaiscript::constructor<crook::KeyEvents()>()},
        {
        {chaiscript::fun(&crook::KeyEvents::onKeyDown), "onKeyDown"},
        {chaiscript::fun(&crook::KeyEvents::onKeyUp), "onKeyUp"},
        {chaiscript::fun(&crook::KeyEvents::onKeyType), "onKeyType"}
     });

     //window events
     chaiscript::utility::add_class<crook::WindowEvents>(*m,
        "WindowEvents",{chaiscript::constructor<crook::WindowEvents()>()},
        {
        {chaiscript::fun(&crook::WindowEvents::onClose), "onClose"},
        {chaiscript::fun(&crook::WindowEvents::onRepositionEnd), "onRepositionEnd"},
        {chaiscript::fun(&crook::WindowEvents::onRepositionStart), "onRepostionStart"},
        {chaiscript::fun(&crook::WindowEvents::onResize), "onResize"},
        {chaiscript::fun(&crook::WindowEvents::onFoucs), "onFocus"}
     });
      chaiscript::utility::add_class<crook::WindowEventObject>(*m,
        "WindowEventObject",
        {},
        {
        {chaiscript::fun(&crook::WindowEventObject::height), "height"},
        {chaiscript::fun(&crook::WindowEventObject::width), "width"},
        {chaiscript::fun(&crook::WindowEventObject::windowX), "windowX"},
        {chaiscript::fun(&crook::WindowEventObject::windowY), "windowY"}
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