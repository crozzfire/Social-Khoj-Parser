
%token_type {const char*}  

%include {   
#include <iostream>  
#include "grammar.h"
#include "querytype.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lexglobal.h"
}  

%left LIKES MOODS FROM HATES INFO.

%syntax_error {  
  std::cout << "Syntax error!" << std::endl;  
}   
   
result ::= expr(A).    

expr(A) ::= LIKES VALUE(B).   { Data *data=Data::getInstance();const char* t_=B;data->likes.push_back(t_);A=B; }
expr(A) ::= HATES VALUE(B).   { Data *data=Data::getInstance();const char* t_=B;data->hates.push_back(t_);A=B;}
expr(A) ::= FROM VALUE(B).   { Data *data=Data::getInstance();const char* t_=B;data->from.push_back(t_);A=B;}
expr(A) ::= MOODS VALUE(B).   {Data *data=Data::getInstance();const char* t_=B;data->moods.push_back(t_);A=B;}
expr(A) ::= INFO VALUE(B).   { Data *data=Data::getInstance();const char* t_=B;data->info.push_back(t_);A=B;}

expr(A) ::= VALUE(B). {A=B;}  

