#include <stdio.h>
#include <string.h>
#include <ctype.h>

// struct to hold mappings
struct MorseCode {
    char character;
    const char *code;
};

// lookup table
const struct MorseCode morseTable[] = {
    {'A', ".-"},
    {'B', "-..."}, 
    {'C', "-.-."}, 
    {'D', "-.."}, 
    {'E', "."},
    {'F', "..-."}, 
    {'G', "--."}, 
    {'H', "...."}, 
    {'I', ".."}, 
    {'J', ".---"},
    {'K', "-.-"}, 
    {'L', ".-.."}, 
    {'M', "--"}, 
    {'N', "-."}, 
    {'O', "---"},
    {'P', ".--."}, 
    {'Q', "--.-"}, 
    {'R', ".-."}, 
    {'S', "..."}, 
    {'T', "-"},
    {'U', "..-"}, 
    {'V', "...-"}, 
    {'W', ".--"}, 
    {'X', "-..-"}, 
    {'Y', "-.--"},
    {'Z', "--.."}, 
    {'0', "-----"}, 
    {'1', ".----"}, 
    {'2', "..---"}, 
    {'3', "...--"},
    {'4', "....-"}, 
    {'5', "....."}, 
    {'6', "-...."}, 
    {'7', "--..."}, 
    {'8', "---.."},
    {'9', "----."}
};

const int morseTableSize = sizeof(morseTable) / sizeof(morseTable[0]);

// find charactes from rancode
char morseToChar(const char *morse) {
    for (int i = 0; i < morseTableSize; i++) {
        if (strcmp(morse, morseTable[i].code) == 0) {
            return morseTable[i].character;
        }
    }
    return '?'; // return ? on unknown
}

// translate rancode
void ran2words(const char *morseInput, char *textOutput) {
    char morseChar[10]; // Temporary buffer for each Morse character
    int morseIndex = 0;
    int outputIndex = 0;
    
    for (int i = 0; morseInput[i] != '\0'; i++) {
        if (morseInput[i] == ' ' || morseInput[i] == '/') {
            // End of a Morse character
            if (morseIndex > 0) {
                morseChar[morseIndex] = '\0';
                textOutput[outputIndex++] = morseToChar(morseChar);
                morseIndex = 0;
            }
            
            // Handle word space
            if (morseInput[i] == '/') {
                textOutput[outputIndex++] = ' ';
            }
        } else {
            // Build the Morse character
            if (morseIndex < 9) {
                morseChar[morseIndex++] = morseInput[i];
            }
        }
    }
    
    // Handle the last Morse character if there's no trailing space
    if (morseIndex > 0) {
        morseChar[morseIndex] = '\0';
        textOutput[outputIndex++] = morseToChar(morseChar);
    }
    
    textOutput[outputIndex] = '\0';
}

int main() {
    char morseInput[500];
    char textOutput[200];
    
    printf("Morse Code Translator\n");
    printf("Enter Morse code (use '.' for dot, '-' for dash, ' ' to separate letters, '/' to separate words):\n");
    printf("> ");
    
    // Read input
    fgets(morseInput, sizeof(morseInput), stdin);
    
    // Remove newline character
    morseInput[strcspn(morseInput, "\n")] = '\0';
    
    // Translate Morse code
    ran2words(morseInput, textOutput);
    
    printf("\nout:\n%s\n", textOutput);
    
    return 0;
}