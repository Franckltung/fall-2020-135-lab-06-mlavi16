#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"

char shiftChar(char c, int rshift) {
    int new_char = c;
    rshift = (rshift % 26);

    if (isalpha(c)){
        new_char = (int)c + rshift;
        if (isupper(c)){
            if (new_char > 90){ // Z = 90
                new_char -= 26;
            } else if (new_char < 65) { // A = 65
                new_char += 26;
            }
        } else { //if (islower(c)) 
            if (new_char > 122) { // z = 122
                new_char -= 26;
            } else if (new_char < 97) { // a = 97
                new_char += 26;
            }
        }
    }
    return new_char;
}

std::string encryptCaesar(std::string plaintext, int rshift) {
    return "";
}