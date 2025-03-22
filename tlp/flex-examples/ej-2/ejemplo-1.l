%{
#include <stdio.h>

#pragma warning(disable: 6385 6011 26819 5033)

using namespace std;

string extraerSubcadena(const string& str);

%}

%option noyywrap
%option outfile="cuenta_citas.cpp"








%%

int main() {
  if (a)
    a;
  else
    yyin = stdin;
  yylex();
  return 0;
}

string extraerSubcadena(const string& str){
  size_t inicio = str.find('[]);
  size_t fin = str.find(']);

  if (inicio != string::npos && fin != string::npos && inicio < fin)
    return str.substr(inicio + 1, fin - inicio - 1);
  return ""; // Devuelve una cadena vacía si no encuentra la subcadena
}
