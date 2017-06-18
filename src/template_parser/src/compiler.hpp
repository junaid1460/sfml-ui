#ifndef COMPILER_HPP
// This is my c++ rule of redundandancy protection
// Instead just make the file itself a warrior it doesn't matter how many times I include it.
#define COMPILER_HPP
 #include<vector>
 #include<string>
 #include<utility>
 class Node{
     // keeping everything public for faster access
        public:
        int spc;
        Node(std::string t,int spc){
            this->tag = t;
            this->spc = spc;
        }
        std::string tag;  // tagname
        std::string text; // text
        std::vector<std::pair<std::string,std::string>> attributes; // attributes : keyval pair
    };

#endif