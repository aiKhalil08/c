#include<stdio.h>

#define MAXLENGTH 5000

void readProgram(char program[]);
int checkErrors(char program[]);

int main() {
    char program[MAXLENGTH];
    int result;
    
    readProgram(program);
    result = checkErrors(program);

    printf("---This is the output---\n");

    if (result == 1)
        printf("Unmatching number of (\n");
    else if (result == 2)
        printf("Unmatching number of [\n");
    else if (result == 3)
        printf("Unmatching number of {\n");
    else if (result == 0)
        printf("Program is clean\n");
    else
        printf("Unknown status\n");
}

void readProgram(char program[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF; ++i) {
        program[i] = c;
    }

    program[i] = '\0';
}

int checkErrors(char program[]) {
    int openParentheses = 0, openBrackets = 0, openBraces = 0;
    int inQuotes = 0, inComment = 0;
    char c, nextC;
    int shouldIgnore = 0;

    for (int i = 0; (c = program[i]) != '\0'; ++i) {
        // check if in comments
        nextC = program[i+1];
        if (inComment == 0 && ((c == '/' && nextC == '/') || (c == '/' && nextC == '*')))
            inComment = nextC == '/' ? 1 : 2;
        if (inComment == 1 && c == '\n')
            inComment = 0;
        if (inComment == 2 && c == '*' && (nextC == '/')){
            inComment = 0;
            ++i;
        }
        
        // check if in quotes
        if (inComment == 0 && inQuotes == 0 && (c == '"' || c == '\''))
            inQuotes = 1;
        else if (inQuotes == 1 && (c == '"' || c == '\'') && (program[i-1] != '\\'))
            inQuotes = 0;


        shouldIgnore = inQuotes || inComment;

        if (shouldIgnore == 0) {
            // check for parentheses
            if (c == '(')
                ++openParentheses;
            else if (c == ')')
                --openParentheses;

            // check for brackets
            if (c == '[')
                ++openBrackets;
            else if (c == ']')
                --openBrackets;

            // check for braces
            if (c == '{')
                ++openBraces;
            else if (c == '}')
                --openBraces;
        }
    }

    if (openParentheses != 0)
        return 1;
    else if (openBrackets != 0)
        return 2;
    else if (openBraces != 0)
        return 3;
    else
        return 0;
}