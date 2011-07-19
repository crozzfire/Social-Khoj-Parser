%{
#include <string.h>
#include "grammar.h"
#include "lexglobal.h" 
%}

%%


"likes:"           {  yysval.sval = (char*)yytext;return LIKES; }
"hates:"           {  yysval.sval = (char*)yytext;return HATES; }
"from:"           {  yysval.sval = (char*)yytext;return FROM; }
"moods:"           {  yysval.sval = (char*)yytext;return MOODS; }
"info:"           {  yysval.sval = (char*)yytext;return INFO; }

[A-Za-z][A-Za-z0-9]*                   {
												yysval.sval = (char*)yytext; 
                                                return VALUE;
                                      }
                                               
[ \t]   								{}
%%

/**
 * yyerror() is invoked when the lexer or the parser encounter
 * an error. The error message is passed via *s
 *
 *
 */
void yyerror(char *s)
{
  printf("error: %s",s);

}

int yywrap(void)
{
  return 1;
}
