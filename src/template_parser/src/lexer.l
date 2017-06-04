%option noyywrap
%{
    #include<stdio.h>
    #include<string>
    #include<vector>
    #include<map>
    #include<algorithm>
    #include<utility>
    #include"compiler.hpp"
    #include"parser.hpp"
   #define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
    std::vector<Node> data;
    std::vector<Node>::iterator current;
    extern YYSTYPE yylval;
    int bc = 0;
    int spc = 0;
    
%}
%x REALLYEND
name            [a-zA-Z][a-zA-Z\_\-]*
att             [\*\#]?[\_\-\.a-zA-Z]*
lb              [\(]
rb              [\)]
sp              [ ]
eq              [=]
comma           [\,]
dq              [\"]
sq              [\']
edq             [\\][\"]
esq             [\\][\']
nl              [\n]
lsb             [\[]
rsb             [\]]
%s BODY BNAME ATTR GOTOATTR TEXT EQVAL SQVAL  ATTEQ DQVAL ETC
%%
<INITIAL>{name}                 {
                                    printf("%s\nThis is line : %d %s\n",KGRN,yylineno,KNRM);
                                    yylval = std::string(yytext); 
                                    data.push_back(Node(yylval,spc));
                                    current = data.end() -1;
                                    if(spc%4!=0){return ERROR;}
                                    yylineno++;
                                    printf("init:name:'%s'  returned\n",yytext);
                                    BEGIN(BODY);
                                    return NAME;
                                }
<INITIAL>{sp}                   {   spc++;}
<INITIAL>{nl}                   {   spc=0;yylineno++;}

<BODY>{lb}                      {
                                    yylval = std::string(yytext); 
                                    printf("body:lb :'%s' returned\n",yytext);
                                    bc++;
                                    BEGIN(ATTR);
                                    return LB;
                                }
<BODY><<EOF>>                   {   printf("body:eot:'%s' returned\n",yytext);BEGIN(REALLYEND); return _EOF;}
<BODY>{sp}                      {
                                    yylval = std::string(yytext); 
                                    printf("body:sp:'%s'  returned\n",yytext);
                                    BEGIN(TEXT);
                                }
<BODY>{nl}                      {   BEGIN(INITIAL);spc=0;   }
<BODY>.                         {   return ERROR;   }
<ATTR>{lb}                      {
                                    BEGIN(BNAME);
                                    yylval = std::string(yytext); 
                                    printf("attr:lb:'%s'  returned\n",yytext);bc++;return LB;}
<ATTR>{lsb}                     {   
                                    BEGIN(BNAME);
                                    yylval = std::string(yytext); 
                                    printf("attr:lsb:'%s'  returned\n",yytext);
                                    bc++;
                                    return LSB;
                                }
<ATTR>{rb}                      {
                                    yylval = std::string(yytext); 
                                    printf("attr:rb:'%s'  returned\n",yytext);
                                    bc--;
                                    if(bc==0){BEGIN(TEXT);}
                                    return RB;
                                }
<ATTR>{att}                     {
                                    yylval = std::string(yytext); 
                                    printf("attr:att:'%s'  returned\n",yytext);
                                    BEGIN(ATTEQ);
                                    return ATT;
                                }
<ATTR>.      {return ERROR;}
<BNAME>{att}                    {   yylval = std::string(yytext);printf("bname:att:'%s'  returned\n",yytext);return ATT;}
<BNAME>{rb}                     {   yylval = std::string(yytext);printf("bname:rb:'%s'  returned\n",yytext);bc--;BEGIN(ATTEQ);return RB;}
<BNAME>{rsb}                    {   yylval = std::string(yytext);printf("bname:rsb:'%s'  returned\n",yytext);bc--;BEGIN(ATTEQ);return RSB;}
<BNAME>.      {return ERROR;}
<ATTEQ>{eq}                     {
                                    yylval = std::string(yytext); 
                                    printf("atteq:eq:'%s'  returned\n",yytext);BEGIN(EQVAL);return EQ;}
<ATTEQ>{comma}                  {   BEGIN(ATTR);return COMMA;}
<ATTEQ>{rb}                     {   printf("atteq:rb:'%s'  returned\n",yytext);bc--;BEGIN(TEXT);return RB;}
<ATTEQ>.                        {   return ERROR;}
<EQVAL>{sq}                     {
                                    yylval = std::string(yytext); 
                                    printf("eqval:sq :'%s' returned\n",yytext);BEGIN(SQVAL);return SQ;}
<EQVAL>{dq}                     {
                                    yylval = std::string(yytext); 
                                    printf("eqval:dq :'%s' returned\n",yytext);BEGIN(DQVAL);return DQ;}
<EQVAL>.                        {   return ERROR;}
<DQVAL>{edq}                    {
                                    yylval = std::string(yytext); 
                                    printf("dqval:any :'%s' returned\n",yytext);return ANY;}
<DQVAL>{dq}                     {
                                    yylval = std::string(yytext); 
                                    printf("dqval:dq:'%s'  returned\n",yytext);BEGIN(GOTOATTR);return DQ;}

<DQVAL>.                      {
                                    yylval = std::string(yytext); 
                                    printf("dqval:any :'%s' returned\n",yytext);return ANY;}


<SQVAL>{esq}                    {
                                    yylval = std::string(yytext); 
                                    printf("sqval:any :'%s' returned\n",yytext);return ANY;}
<SQVAL>{sq}                     {
                                    yylval = std::string(yytext); 
                                    printf("sqval:sq :'%s' returned\n",yytext);BEGIN(GOTOATTR);return SQ;}
<SQVAL>.                        {
                                    yylval = std::string(yytext); 
                                    printf("sqval:any :'%s' returned\n",yytext);return ANY;}

<GOTOATTR>{comma}               {   BEGIN(ATTR);return COMMA;}
<GOTOATTR>{rb}                  {
                                    yylval = std::string(yytext); bc--;
                                    printf("gotoattr:rb :'%s' returned\n",yytext);BEGIN(TEXT);return RB;}
<GOTOATTR>.                     {   return ERROR;}

<TEXT>{nl}                      {
                                    spc = 0;
                                    yylval = std::string(yytext); std::cout<<"\n\nbraces :"<<bc<<"\n";
                                    printf("text:eot:'%s'  returned\n","\\n");BEGIN(INITIAL); return EOT;}
<TEXT>.                        {
                                    yylval = std::string(yytext); 
                                    printf("text:any:'%s' returned\n",yytext);return ANY;}
<TEXT><<EOF>>                   {
                                    yylval = std::string(yytext); 
                                    printf("text:eot:'%s' returned\n",yytext);BEGIN(ETC); return EOT;}


<ETC><<EOF>>                {   std::cout<<"returned EOF: \n"; BEGIN(REALLYEND); return _EOF; }

<INITIAL><<EOF>>                {   std::cout<<"returned EOF: \n"; BEGIN(REALLYEND); return _EOF; }
<REALLYEND><<EOF>>              {   std::cout<<"returned eof: \n"; return 0; }
%%