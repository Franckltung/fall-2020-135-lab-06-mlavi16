#include <iostream>
#include "funcs.h"
#include <string>
#include <cctype>

void test_ascii(std::string str) {
    std::string output = "";
    for (int i = 0; i < str.length(); i++) {        
        std::cout << str[i] << " " << (int)str[i] << "\n";
    }
    std::cout << output;
}

