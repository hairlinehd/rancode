#include <stdio.h>
#include <string.h>
#include <ctype.h>

// struct to hold mappings
struct ranCode {
    char character;
    const char *code;
};

// lookup table
const struct ranCode ranTable[] = {
    {'A', "ra"},
    {'B', "arrr"}, 
    {'C', "arar"}, 
    {'D', "arr"}, 
    {'E', "r"},
    {'F', "rrar"}, 
    {'G', "aar"}, 
    {'H', "rrrr"}, 
    {'I', "rr"}, 
    {'J', "raaa"},
    {'K', "ara"}, 
    {'L', "rarr"}, 
    {'M', "aa"}, 
    {'N', "ar"}, 
    {'O', "aaa"},
    {'P', "raar"}, 
    {'Q', "aara"}, 
    {'R', "rar"}, 
    {'S', "rrr"}, 
    {'T', "a"},
    {'U', "rra"}, 
    {'V', "aaar"}, 
    {'W', "raa"}, 
    {'X', "arra"}, 
    {'Y', "araa"},
    {'Z', "aarr"},
    {'0', "aaaaa"}, 
    {'1', "naaaa"}, 
    {'2', "nnaaa"}, 
    {'3', "nnnaa"},
    {'4', "nnnna"}, 
    {'5', "nnnnn"}, 
    {'6', "annnn"}, 
    {'7', "aannn"}, 
    {'8', "aaann"},
    {'9', "aaaan"},
    {' ', "ts"}
};

const int ranTableSize = sizeof(ranTable) / sizeof(ranTable[0]);

// find charactes from rancode
char ranToChar(const char *ran) {
    for (int i = 0; i < ranTableSize; i++) {
        if (strcmp(ran, ranTable[i].code) == 0) {
            return ranTable[i].character;
        }
    }
    return '?'; // return ? on unknown
}

// translate rancode
void ran2words(const char *ranInput, char *textOutput) {
    char ranChar[10]; 
    int ranIndex = 0;
    int outputIndex = 0;
    
    for (int i = 0; ranInput[i] != '\0'; i++) {
        if (ranInput[i] == ' ' || ranInput[i] == '/') {
            // end of a character
            if (ranIndex > 0) {
                ranChar[ranIndex] = '\0';
                textOutput[outputIndex++] = ranToChar(ranChar);
                ranIndex = 0;
            }
            
            // ts
            if (ranInput[i] == 'ts') {
                textOutput[outputIndex++] = ' ';
            }
        } else {
            // build the ran!!!
            if (ranIndex < 9) {
                ranChar[ranIndex++] = ranInput[i];
            }
        }
    }
    
    if (ranIndex > 0) {
        ranChar[ranIndex] = '\0';
        textOutput[outputIndex++] = ranToChar(ranChar);
    }
    
    textOutput[outputIndex] = '\0';
}

int main() {
    char ranInput[500];
    char textOutput[200];
    
    printf("rancode to words translator\n");
    printf("use 'r' for dot, 'a' for dash, space to separate letters, and 'ts' to separate words\n");
    printf("> ");
    
    fgets(ranInput, sizeof(ranInput), stdin);
    ranInput[strcspn(ranInput, "\n")] = '\0';
    ran2words(ranInput, textOutput);
    
    printf("%s\n",textOutput);
    
    return 0;
}