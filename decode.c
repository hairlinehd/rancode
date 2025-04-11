#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// struct to hold mappings
struct ranCode {
    char character;
    const char *code;
};

// lookup table with letters, numbers, and punctuation
const struct ranCode ranTable[] = {
    {'a', "ra"}, 
    {'b', "arrr"}, 
    {'c', "arar"}, 
    {'d', "arr"}, 
    {'e', "r"},
    {'f', "rrar"}, 
    {'g', "aar"}, 
    {'h', "rrrr"}, 
    {'i', "rr"}, 
    {'j', "raaa"},
    {'k', "ara"}, 
    {'l', "rarr"}, 
    {'m', "aa"}, 
    {'n', "ar"}, 
    {'o', "aaa"},
    {'p', "raar"}, 
    {'q', "aara"}, 
    {'r', "rar"}, 
    {'s', "rrr"}, 
    {'t', "a"},
    {'u', "rra"}, 
    {'v', "aaar"}, 
    {'w', "raa"}, 
    {'x', "arra"}, 
    {'y', "araa"},
    {'z', "aarr"},

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
    {' ', "ts"},

    {'.', "rrara"}, 
    {',', "rraar"}, 
    {':', "aaara"}, 
    {'?', "rarra"},
    {'-', "arraa"}, 
    {'(', "arara"}, 
    {')', "raarra"},
    {'"', "aarrr"},
    {'&', "rrrra"}, 
    {'!', "rrraa"}, 
    {';', "raraa"}
};

const int ranTableSize = sizeof(ranTable) / sizeof(ranTable[0]);

char ranToChar(const char *ran) {
    for (int i = 0; i < ranTableSize; i++) {
        if (strcmp(ran, ranTable[i].code) == 0) {
            return ranTable[i].character;
        }
    }
    return '?'; // for unknown characters
}

// translate rancode
void ran2words(const char *ranInput, char *textOutput) {
    char ranChar[10];
    int ranIndex = 0;
    int outputIndex = 0;
    bool capitalizeNext = false;
    
    for (int i = 0; ranInput[i] != '\0'; i++) {
        // check for capital letters
        if (ranInput[i] == '!' && ranIndex == 0) {
            capitalizeNext = true;
            continue;
        }
        
        if (ranInput[i] == ' ' || ranInput[i] == '/') {
            // end of a character
            if (ranIndex > 0) {
                ranChar[ranIndex] = '\0';
                char decoded = ranToChar(ranChar);
                if (capitalizeNext && isalpha(decoded)) {
                    decoded = toupper(decoded);
                    capitalizeNext = false;
                }
                textOutput[outputIndex++] = decoded;
                ranIndex = 0;
            }
            
            // handle word space
            if (strncmp(&ranInput[i], "ts", 2) == 0) {
                textOutput[outputIndex++] = ' ';
                i++; // skip the 's' in "ts"
            }
        } else {
            if (ranIndex < 9) {
                ranChar[ranIndex++] = ranInput[i];
            }
        }
    }

    if (ranIndex > 0) {
        ranChar[ranIndex] = '\0';
        char decoded = ranToChar(ranChar);
        if (capitalizeNext && isalpha(decoded)) {
            decoded = toupper(decoded);
        }
        textOutput[outputIndex++] = decoded;
    }
    
    textOutput[outputIndex] = '\0';
}

int main() {
    char ranInput[500];
    char textOutput[200];

    printf("rancode to words translator\n");
    printf("use 'r' for dot ('n' when writing numbers), 'a' for dash, space to separate letters, and 'ts' to separate words\n");
    printf("> ");
    
    fgets(ranInput, sizeof(ranInput), stdin);
    ranInput[strcspn(ranInput, "\n")] = '\0';
    ran2words(ranInput, textOutput);
    
    printf("%s\n",textOutput);
    
    return 0;
}