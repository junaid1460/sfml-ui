 #include<vector>
 #include<string>
 #include<utility>
 class Node{
        public:
        int spc;
        Node(std::string t,int spc){
            this->tag = t;
            this->spc = spc;
        }
        std::string tag;
        std::string text;
        std::vector<std::pair<std::string,std::string>> attributes;
    };