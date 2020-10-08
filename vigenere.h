#pragma once

std::string encryptVigenere(std::string plain_text, std::string keyword);
char keywordEncryption(char c, char key);
void increment_keyword_ch(int& cur_shift, int max_shift);