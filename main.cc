#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>

const std::vector<std::string> rancode = {
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
"ts", // word separator

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

char ran2char(const std::string& code) {
    auto it = std::find(rancode.begin(), rancode.end(), code);
    if (it != rancode.end()) {
        int index = std::distance(rancode.begin(), it);
        if (index < 26) return 'a' + index; // letters
        if (index < 36) return '0' + (index - 26); // numbers
        if (index == 36) return ' '; // space
        switch (index) {
            case 37: return '.'; 
            case 38: return ',';  
            case 39: return ':';
            case 40: return '?';  
            case 41: return '-';  
            case 42: return '(';
            case 43: return ')';  
            case 44: return '"';  
            case 45: return '&';
            case 46: return '!';  
            case 47: return ';';

            default: return '?';
        }
    }
    return '?';
}

void encodeRancode(const std::string& text) {
    for (char c : text) {
        if (isalpha(c)) {
            if (isupper(c)) {
                std::cout << "!" << rancode[toupper(c) - 'A'] << " ";
            } else {
                std::cout << rancode[toupper(c) - 'A'] << " ";
            }
        } 
        else if (isdigit(c)) {
            std::cout << rancode[c - '0' + 26] << " ";
        } 
        else if (c == ' ') {
            std::cout << "ts ";
        }
        else {
            switch (c) {
                case '.':  std::cout << rancode[37] << " "; break;  
                case ',':  std::cout << rancode[38] << " "; break; 
                case ':':  std::cout << rancode[39] << " "; break; 
                case '?':  std::cout << rancode[40] << " "; break;
                case '-':  std::cout << rancode[41] << " "; break;  
                case '(':  std::cout << rancode[42] << " "; break;  
                case ')':  std::cout << rancode[43] << " "; break;  
                case '"':  std::cout << rancode[44] << " "; break;  
                case '&':  std::cout << rancode[45] << " "; break;  
                case '!':  std::cout << rancode[46] << " "; break;  
                case ';':  std::cout << rancode[47] << " "; break;  
                default: continue;
            }
        }
    }
    std::cout << std::endl;
}

void decodeRancode(const std::string& rancodeInput) {
    std::istringstream iss(rancodeInput);
    std::string token;
    bool capitalizeNext = false;
    
    while (iss >> token) {
        if (token == "ts") {
            std::cout << ' ';
            continue;
        }
        
        if (token[0] == '!') {
            capitalizeNext = true;
            token = token.substr(1);
        }
        
        char decoded = ran2char(token);
        if (capitalizeNext && isalpha(decoded)) {
            decoded = toupper(decoded);
            capitalizeNext = false;
        }
        std::cout << decoded;
    }
    std::cout << std::endl;
}

bool isInputRancode(const std::string& input) {
    for (char c : input) {
        if (!(c == 'a' || c == 'r' || c == 'n' || c == 't' || c == 's' || c == '!' || c == ' ' || c == '/')) {
            return false;
        }
    }
    return true;
}

int main() {    
    std::string input;
    
    std::cout << "rancode encoder & decoder" << std::endl;
    std::cout << "> ";
    
    if (std::getline(std::cin, input)) {
        if (input.empty()) {
            std::cout << "no input" << std::endl;
            return 0;
        }
        
        if (isInputRancode(input)) {
            std::cout << "text: ";
            decodeRancode(input);
        } else {
            std::cout << "rancode: ";
            encodeRancode(input);
        }
    }
    
    return 0;
}