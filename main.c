#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Expanded Rancode table
const char *rancode[] = {
    "ra", // a
    "arrr", // b
    "arar", // c 
    "arr", // d
    "r", // e
    "rrar", // f
    "aar", // g
    "rrrr", // h
    "rr", // i
    "raaa", // j
    "ara", // k
    "rarr", // l
    "aa", // m
    "ar", // n
    "aaa", // o
    "raar", // p
    "aara", // q
    "rar", // r
    "rrr", // s
    "a", // t
    "rra", // u
    "aaar", // v
    "raa", // w
    "arra", // x
    "araa", // y
    "aarr", // z
    "aaaaa", // 0
    "naaaa", // 1
    "nnaaa", // 2
    "nnnaa", // 3
    "nnnna", // 4
    "nnnnn", // 5
    "annnn", // 6
    "aannn", // 7
    "aaann", // 8
    "aaaan", // 9
    "ts", // word seperator

    // punctuation
    "rrara",   // . (period)
    "rraar",   // , (comma)
    "aaara",   // : (colon)
    "rarra",   // ? (question mark)
    "arraa",   // - (hyphen)
    "arara",   // ( (open parenthesis)
    "raarra",  // ) (close parenthesis)
    "aarrr",   // " (quotation mark)
    "rrrra",   // & (ampersand)
    "rrraa",   // ! (exclamation mark)
    "raraa"    // ; (semicolon)
};

void input2ran(const char *text) {
    for (size_t i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                printf("!%s ", rancode[toupper(c) - 'A']);
            } else {
                printf("%s ", rancode[toupper(c) - 'A']);
            }
        } 
        else if (isdigit(c)) {
            printf("%s ", rancode[c - '0' + 26]);
        } 
        else if (c == ' ') {
            printf("ts ");
        }
        else {
            // Handle punctuation
            switch (c) {
                case '.':  printf("%s ", rancode[37]); break;  
                case ',':  printf("%s ", rancode[38]); break; 
                case ':':  printf("%s ", rancode[39]); break; 
                case '?':  printf("%s ", rancode[40]); break;
                case '-':  printf("%s ", rancode[41]); break;  
                case '(':  printf("%s ", rancode[42]); break;  
                case ')':  printf("%s ", rancode[43]); break;  
                case '"':  printf("%s ", rancode[44]); break;  
                case '&':  printf("%s ", rancode[45]); break;  
                case '!':  printf("%s ", rancode[46]); break;  
                case ';':  printf("%s ", rancode[47]); break;  
                default: continue;
            }
        }
    }
    printf("\n");
}

int main() {    
    char input[256];
    
    printf("rancode encoder\n");
    printf("> ");

    if (fgets(input, sizeof(input), stdin)) {
        // remove line breaks
        input[strcspn(input, "\n")] = '\0';
        
        printf("rancode: ");
        input2ran(input);
    } 
    else {
        printf("error reading input\n");
    }
    
    return 0;
}