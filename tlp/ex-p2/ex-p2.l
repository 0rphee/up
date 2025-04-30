%{

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

std::unordered_map<std::string, int> frecuencia;

bool is_connective(const std::string& word) {
    static const std::string connectives[] = {"the", "is", "in", "on", "or", "and", "an", "a"};
    for (const std::string& conn : connectives)
        if (word == conn)
            return true;
    return false;
}

#define YY_DECL int yylex()

%}

%option noyywrap

WORD    [a-zA-Z]+

%%

{WORD} {
    std::string word(yytext);
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    if (is_connective(word)) {
        frecuencia[word]++;
    } else {
        std::cout << word;
    }
}

\n {
    std::cout << yytext;
}

. {
    std::cout << yytext;
}

%%

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " INPUTFILE" << std::endl;
        return 1;
    }
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        std::cerr << "No se pudo abrir el archivo: " << argv[1] << std::endl;
        return 1;
    }

    yyin = input_file;
    yylex();
    fclose(input_file);

    std::cout << "\n\n--- Frecuencia de palabras ---\n\n";
    
    for (const std::pair<const std::string, int>& items : frecuencia) {
        std::cout << items.first << ": " << items.second << std::endl;
    }

    return 0;
}
