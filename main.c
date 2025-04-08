#include <stdio.h>
#include <string.h>
#include <ctype.h>

// rancode table
const char *morse_code[] = {
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
    "aaaan", // 4
    "nnnnn", // 5
    "annnn", // 6
    "aannn", // 7
    "aaann", // 8
    "aaaan", // 9
    "ts",    // word seperator
};

void input2ran(const char *text) {
    for (size_t i = 0; text[i] != '\0'; i++) {
        char c = toupper(text[i]);
        if (c >= 'A' && c <= 'Z') {
            printf("%s ", morse_code[c - 'A']);
        } else if (c >= '0' && c <= '9') {
            printf("%s ", morse_code[c - '0' + 26]);
        } else if (c == ' ') {
            printf("ts "); //ts to seperate words
        } else {
            // dont worry about unsupported characters
            continue;
        }
    }
    printf("\n");
}

int main() {    
    char input[256];
    
    printf("input to rancode translator\n");
    printf("> ");

    if (fgets(input, sizeof(input), stdin)) {
        // remove line breaks
        input[strcspn(input, "\n")] = '\0';
        
        printf("rancode: ");
        input2ran(input);
    } else {
        printf("error reading input\n");
    }
    
    return 0;
}
