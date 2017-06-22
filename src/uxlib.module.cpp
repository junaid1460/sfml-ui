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

    m->add(chaiscript::fun(&addEventListener),"addEventListener");

    //MouseEvent registration
    chaiscript::utility::add_class<crook::events::objects::MouseEventObject>(*m,
        "MouseEventObject",
        {},
        {
        {chaiscript::fun(&crook::events::objects::MouseEventObject::x), "x"},
       {chaiscript::fun(&crook::events::objects::MouseEventObject::y), "y"}
        });
    chaiscript::utility::add_class<crook::ui::Component>(*m,
    "Component",
        {},
        {
            {chaiscript::fun(&crook::ui::Component::addEventListener),"addEventListener"}
        }
    );

    chaiscript::utility::add_class<crook::events::objects::EventObject>(*m,
        "EventObject",{},
        {
            
     });

    //window functions
    chaiscript::utility::add_class<crook::Window>(*m,
        "Window",{},
        {
            
     });

     //keyboard Event registration
    

     //window events
  
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