#include <iostream>
#include <string>
#include <cctype>
#include "decryption.h"
#include "caesar.h"
#include "vigenere.h"

std::string decryptCaesar(std::string cipher_text, int rshift) {
    return encryptCaesar(cipher_text, -rshift);
}

std::string decryptVigenere(std::string cipher_text, std::string keyword) {
    std::string encrypted_text = "";
    int cur_shift = 0;
    int max_shift = keyword.length() - 1;
    int shifts [keyword.length()];

    for (int i = 0; i < keyword.length(); i++){
        shifts[i] = ((int)tolower(keyword[i]) - 97) * -1; // a = 97
    }
    for (int i = 0; i < cipher_text.length(); i++) {
        if (isalpha(cipher_text[i])) {
            encrypted_text += shiftChar(cipher_text[i], shifts[cur_shift]);
            cur_shift = cur_shift < max_shift ? cur_shift + 1 : 0;
        } else {
            encrypted_text += cipher_text[i];
        }
    }
    return encrypted_text;
}
