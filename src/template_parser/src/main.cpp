#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include"compiler.hpp"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
namespace output{

    void color(const char *t){
        std::cout<<t;
    }
}
extern std::vector<Node> data;
extern std::ofstream file;
   extern int yyparse();
   extern int yylex();
   extern void yyerror(const char *);
extern int yylineno;

int main(){
    
    int res = yyparse();
      output::color(KMAG);
   std::cout<<"\n\n";
    for(auto t:data){
        output::color(KBLU);
        std::cout<<t.tag<<"("<<t.spc<<") ";
        output::color(KGRN);
        
        std::cout<<":";
        output::color(KWHT);
        
        std::cout<<t.text<<std::endl;
        for(auto t:t.attributes){
        output::color(KRED);
            
            std::cout<<"\t";
        
            
            std::cout<<t.first;
            output::color(KWHT);
            std::cout<<" : ";
            output::color(KCYN);
            std::cout<<t.second<<"\n";
        }
    }
   
    if(!res){
        output::color(KGRN);
         std::cout<<"\nsuccessful compilation!\n";
    }
    else {
        output::color(KRED);
        std::cout<<"\ncompilation wasn't successful!"<<yylineno<<"\n";
    }
    std::cout<<"\n";
  

     output::color(KWHT);
    return 0;
}

