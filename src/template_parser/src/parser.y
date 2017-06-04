%{
    #include<iostream>
    #include "lexer.cpp"
    #include <fstream>
    std::string tmps;
    int yylex(void);
    void yyerror(const char *);

%}
%define api.value.type  {std::string}
%token NAME ATT ERROR LSB RSB EOT DQ SP FO FC LB RB SQ COMMA ANY  ESCDBQ ESCSQ  NL _EOF EQ TEXT


%right NL
%start grammar
%%
grammar: tags _EOF {}
;

tags:tags NAME attr text {   current->text = $4; current--;}
    |
        ;
attr:LB attributes RB                   {}
|
;
attributes: attributes attrname value    {current->attributes.push_back(std::make_pair($2,$3));}
            |attributes COMMA
            |
            ;
attrname: LB ATT RB      {$$ = $1 + $2 + $3; }
        |LSB ATT RSB     {$$ = $1 + $2 + $3; }
        | ATT            {$$ = $1; std::cout<<"\n\nThis is it: "<<$1<<"\n";}
        ;
value:  EQ SQ content SQ    {$$ = tmps;tmps ="";}
        |EQ DQ content DQ   {$$ = tmps;tmps ="";}
        |   {$$="";}
        ;
content:    ANY content {tmps = $1 + tmps;}
            |
            ;


text: tt EOT    {$$ = tmps;tmps = "";}
    |           {$$="";}
;

tt: ANY  tt{ tmps = $1 + tmps;}
    |
    
    ;
    
%%

void yyerror(const char * t){
    std::cout<<std::endl<<t<<std::endl<<yylineno;
}