#include "./uxlib.module.cpp"
void evalFile(std::string fileName){
    chaiscript::ChaiScript script;
    script.add(uxLibrary());
    script.eval_file(fileName);
}

void render(){
    bool r = false;
    do{
        r= false;
        for(auto i:windows){
            r|=i->render();
        }
    }while(r);
}