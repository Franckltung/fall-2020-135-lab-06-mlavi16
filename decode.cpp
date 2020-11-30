#include <iostream>
#include <cmath>
#include <cctype>
#include "decode.h"
#include "decryption.h"

std::string decode(std::string encrypted_str) {
    /*
    Function decrypts a string encrypted by the caesar cipher, by trying every rotation and
    calculating its distance to the vector of letter frequencies in the English language.
    @param str a string encrypted by the caesar cipher
    @return decoded_str the decrypted version of the inputed str
    */

    std::string str;
    // frequencies of letters (in order starting from a) in normal texts according to wikipedia
    double freq[26] = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074};
    // frequencies of letters in a specific decrypted str of the given encrypted str
    double str_freq[26];
    // the distance between the frequencies of every decrypted str and normal frequencies
    double dist_arr[26];

    for (int i = 0; i < 26; i++) {
        // gets a possible decrypted string of the input encrypted string
        str = decryptCaesar(encrypted_str, i);

        // gets the frequency of every letter in the decrypted string
        for (int j = 0; j < 26; j++) { 
            char ch = j + 'a';
            str_freq[j] = letter_freq(str, ch);
        }

        // finds how similar the frequences of letters in the decrypted str are to what they're supposed to be in a regular sentence
        dist_arr[i] = squared_dist_bet_freqs(freq, str_freq);
    }

    // finds what shift makes a string with frequences closest to what they're supposed to be in a normal sentence
    int shift = find_best_shift(dist_arr);

    return decryptCaesar(encrypted_str, shift);
}

double letter_freq(std::string str, char ch) {
    // finds and returns the frequency of char ch in string str
    int counter = 0;
    int letter_counter = 0;
    for (int i = 0; i < str.length(); i++){
        if (tolower(str[i]) == tolower(ch)) {
            counter += 1;
        }
        if (isalpha(str[i])) {
            letter_counter += 1;
        }
    }
    return (double)counter / letter_counter;
} 

double squared_dist_bet_freqs(double freq[], double str_freq[]) {
    // Function finds the squared distance between the two arrays
    double dist = 0;
    for (int i = 0; i < 26; i++){
        dist += pow(freq[i] - str_freq[i], 2);
    }
    return dist;
}

int find_best_shift(double dist_arr[]) {
    // finds the smallest element in dist_arr[] and returns its index
    int smallest_num_index = 0;
    for (int i = 1; i < 26; i++){
        if (dist_arr[i] < dist_arr[smallest_num_index]) {
            smallest_num_index = i;
        }
    }
    return smallest_num_index;
}
