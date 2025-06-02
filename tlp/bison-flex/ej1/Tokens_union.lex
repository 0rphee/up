%{
#include "Tokens_union.hpp"

%}

%option outfile = "Flex_Tokens_union.cpp"

%%

^[+-]?\d+$ {
    yyval.integerval = atoi(yytext);
    return TOKENENTERO;
}

^[+-]\?(\d+\.\d*|\.\d+)([eE][+-]?\d+)?$ {
    yyval.floatval = atof(yytext);
    return TOKENFLOTANTE;
}


^(true|false)$ {
    yyval.boolval = !strcmp(yytext, "true");
    return TOKENFLOTANTE;
}

[a-zA-Z0-9] {
    strcpy(yyval.stringval, yytext);
    return TOKENENTERO;
}

[\t\n] {} // ignorar saltos y tabulaciones

. {} // ignorar cualquier otro carácter

%%
