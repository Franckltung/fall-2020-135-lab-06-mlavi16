#pragma once

std::string decode(std::string encrypted_str);
double letter_freq(std::string str, char ch);
double squared_dist_bet_freqs(double freq[], double str_freq[]);
int find_best_shift(double dist_arr[]);
