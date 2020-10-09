/*
Author: Maya Lavi
Course: CSCI-135
Instructor: Zamansky
Assignment: Lab 6
*/
#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"


int main()
{
  std::cout << "Ascii value of: Cat :3 Dog!/\n";
  test_ascii("Cat :3 Dog!/");
  std::cout << "Caesar cipher: \"Hello, World!\", shift: 10 --> " << encryptCaesar("Hello, World!", 10) << std::endl;
  std::cout << "Vigenere cipher: \"Hello, World!\", shift: \"cake\" --> " << encryptVigenere("Hello, World!", "cake") << std::endl;
  std::cout << "Decrypting Caesar cipher: \"" << encryptCaesar("Hello, World!", 10) << "\", shift: 10 --> " << decryptCaesar(encryptCaesar("Hello, World!", 10), 10) << std::endl;
  std::cout << "Decrypting Vigenere cipher: \"" << encryptVigenere("Hello, World!", "cake") << "\", shift: \"cake\" --> " << decryptVigenere(encryptVigenere("Hello, World!", "cake"), "cake") << std::endl;

  return 0;
}
