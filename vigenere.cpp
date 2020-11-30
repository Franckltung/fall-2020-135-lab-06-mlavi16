#include <iostream>
#include <cctype>
#include <string>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plain_text, std::string keyword) {
    std::string encrypted_text = "";
    int cur_shift = 0;
    int max_shift = keyword.length() - 1;
    int shifts [keyword.length()];

    for (int i = 0; i < keyword.length(); i++){
        shifts[i] = (int)tolower(keyword[i]) - 97; // a = 97
    }
    
    for (int i = 0; i < plain_text.length(); i++) {
        if (isalpha(plain_text[i])) {
            encrypted_text += shiftChar(plain_text[i], shifts[cur_shift]);
            cur_shift = cur_shift < max_shift ? cur_shift + 1 : 0; // We only advance cur_shift if we actually shifted a character
        } else {
            encrypted_text += plain_text[i];
        }
    }

    return encrypted_text;
}
