#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include"compiler.hpp"
#include "output.cpp"





extern std::vector<Node> data;
extern std::ofstream file;
   extern int yyparse();
   extern int yylex();
   extern void yyerror(const char *);
extern int yylineno;

int main(){
    
    int res = yyparse();
      output::color::set(output::color::KMAG);
   std::cout<<"\n\n";
    for(auto t:data){
        output::color::set(output::color::KBLU);
        std::cout<<t.tag<<"("<<t.spc<<") ";
        output::color::set(output::color::KGRN);
        
        std::cout<<":";
        output::color::set(output::color::KWHT);
        
        std::cout<<t.text<<std::endl;
        for(auto tmp:t.attributes){
        output::color::set(output::color::KRED);
            
            std::cout<<"\t";
        
            
            std::cout<<tmp.first;
            output::color::set(output::color::KWHT);
            std::cout<<" : ";
            output::color::set(output::color::KCYN);
            std::cout<<tmp.second<<"\n";
        }
    }
   
    if(!res){
        output::color::set(output::color::KGRN);
         std::cout<<"\nsuccessful compilation!\n";
    }
    else {
        output::color::set(output::color::KRED);
        std::cout<<"\ncompilation wasn't successful!"<<yylineno<<"\n";
    }
    std::cout<<"\n";
  

     output::color::set(output::color::KWHT);
    return 0;
}

