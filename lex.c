%{
#include <stdio.h>
#include <string.h>

int identifierCount = 0;
int keywordCount = 0;
int newlineCount = 0;
int tabCount = 0;
int whitespaceCount = 0;
int charCount = 0;

void checkKeyword(char* str) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for",
                             "goto", "if", "int", "long", "register", "return", "short",
                             "signed", "sizeof", "static", "struct", "switch", "typedef",
                             "union", "unsigned", "void", "volatile", "while"};
    int i, flag = 0;

    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], str) == 0) {
            flag = 1;
            keywordCount++;
            break;
        }
    }

    if (flag)
        printf("Keyword: %s\n", str);
    else
        printf("Identifier: %s\n", str);
}
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* {
    checkKeyword(yytext);
    identifierCount++;
}

\n {
    printf("Newline\n");
    newlineCount++;
}

\t {
    printf("Tab\n");
    tabCount++;
}

[ \r\f\v]+ {
    printf("Whitespace\n");
    whitespaceCount++;
}

. {
    printf("Character: %s\n", yytext);
    charCount++;
}

%%

int main() {
    char input[100];  // Assuming input is less than 100 characters

    while (1) {
        printf("Enter code (press Enter to finish):\n");
        fgets(input, sizeof(input), stdin);  // Read input line by line

        if (strcmp(input, "\n") == 0)  // Exit loop if empty line is encountered
            break;

        yy_scan_string(input);  // Set input string for Lex
        yylex();
    }

    printf("\nSummary:\n");
    printf("Identifiers: %d\n", identifierCount);
    printf("Keywords: %d\n", keywordCount);
    printf("Newlines: %d\n", newlineCount);
    printf("Tabs: %d\n", tabCount);
    printf("Whitespaces: %d\n", whitespaceCount);
    printf("Characters: %d\n", charCount);

    return 0;
}

