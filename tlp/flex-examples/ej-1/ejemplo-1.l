%{
unsigned int num_lines = 0;
unsigned int num_chars = 0;
/* #pragma warning(disable: ) */
%}

%%

\n {
        ++num_lines;
        ++num_chars;
   }

.  {
       ++num_chars;
   }

%%

int main() {
    yylex();
    printf( "# of lines = %d, # of chars = %d\n", num_lines, num_chars );
}
