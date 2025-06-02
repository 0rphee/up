%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();

void yyerror(const char *s);

%}

%token TOKENFLOTANTE TOKENTERO TOKENSTRING TOKENBOOL

%union {
	int integerval;
	float floatval;
	char *stringval;
	bool boolval;
}

%%

S   :
        TOKENFLOTANTE
        {
            
        }
    |
        TOKENTERO
        {
            
        }
    |
        TOKENSTRING
        {
            
        }
    |
        TOKENBOOL
        {
            
        }
    ;


%%

void yyerror(const char *s){
    fprintf(stderr, "Error ");
}
