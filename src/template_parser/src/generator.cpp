#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#pragma once

#include "compiler.hpp"

#ifndef IOSTREAM_HPP
#include <iostream>
#endif

#ifndef FSTREAM_HPP
#include <fstream>
#endif

namespace gen{
    char toUpper(char c){
        if(c >= 'a' && c <= 'z')
            return (char)(c + 'a' - 'A');
        else
            return c;
    }
    std::string makeName(std::string name){
        int len = name.length();
        name[0] = gen::toUpper(name[0]);
        for(int  i = 1; i < len;i++){
            if(name[i] == '-'){
                name.erase(name.begin()+i);
                len = name.length();
                name[i] = gen::toUpper(name[i]);
            }
        }
        return name;
    }
    bool makefile(std::vector<Node> data,std::string component){
        std::ofstream file("tmp.cpp");
        file << "#define MODULE_XYZ\n\n class " << makeName(Component) << " { \n";
        for(auto t:data){

            std::cout<<t.tag<<"("<<t.spc<<") ";
            std::cout<<":";
            std::cout<<t.text<<std::endl;
        } 
        file << "}\n";
    }
}

#endif