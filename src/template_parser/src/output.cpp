#ifndef OUTPUT_CPP
#define OUTPUT_CPP

namespace output{
    namespace color{
        const char * KNRM =  "\x1B[0m";
        const char * KRED =  "\x1B[31m";
        const char * KGRN =  "\x1B[32m";
        const char * KYEL =  "\x1B[33m";
        const char * KBLU =  "\x1B[34m";
        const char * KMAG =  "\x1B[35m";
        const char * KCYN =  "\x1B[36m";
        const char * KWHT =  "\x1B[37m";
        #ifndef IOSTREAM_HPP
            #include<iostream>
            #define IOSTREAM_HPP
        #endif
        void set(const char *t){
             std::cout<<t;
        }
    }
    
}

#endif