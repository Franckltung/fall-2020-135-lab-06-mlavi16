#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"
#include "decode.h"

TEST_CASE("encryptCaesar(plain_text, rshift)") {
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("", 5) == "");
    CHECK(encryptCaesar(" ", 5) == " ");
    CHECK(encryptCaesar("m", 5) == "r");
    CHECK(encryptCaesar("32", 5) == "32");
    CHECK(encryptCaesar("Hello.", -2) == "Fcjjm.");
    CHECK(encryptCaesar("Heyyy", 0) == "Heyyy");
    CHECK(encryptCaesar("cookie", 26) == "cookie");
}

TEST_CASE("shiftChar(char, rshift)") {
    CHECK(shiftChar('a', 5) == 'f');
    CHECK(shiftChar('z', 2) == 'b');
    CHECK(shiftChar('a', -2) == 'y');
    CHECK(shiftChar('B', 5) == 'G');
    CHECK(shiftChar('X', 4) == 'B');
    CHECK(shiftChar('C', -5) == 'X');
    CHECK(shiftChar('!', 3) == '!');
    CHECK(shiftChar(' ', 4) == ' ');
    CHECK(shiftChar('3', 3) == '3');
    CHECK(shiftChar('j', -3) == 'g');
    CHECK(shiftChar('f', 0) == 'f');
    CHECK(shiftChar('a', 26) == 'a');
	CHECK(shiftChar('a', -52) == 'a');
}

TEST_CASE("encryptVigenere(plain_text, keyword)") {
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("cake", "helloworld") == "jevp");
    CHECK(encryptVigenere("", "oof") == "");
    CHECK(encryptVigenere("   ", "cake") == "   ");
    CHECK(encryptVigenere("cake 999 cake", "cake") == "eaui 999 eaui");
    CHECK(encryptVigenere("hi ", "") == "hi ");
    CHECK(encryptVigenere("hal", "b") == "ibm");
    CHECK(encryptVigenere("z", "z") == "y");
	CHECK(encryptVigenere("z", "Z") == "y");
    // Lab says "you may assume that the keyword contains only lowercase alphabetic characters a - z."
	// FRANCK: I added support anyway
}

TEST_CASE("decryptCaesar(cipher_text, rshift)") {
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
    CHECK(decryptCaesar("Way to Go!", -5) == "Bfd yt Lt!");
    CHECK(decryptCaesar("", 5) == "");
    CHECK(decryptCaesar(" ", 3) == " ");
    CHECK(decryptCaesar("t", 2) == "r");
    CHECK(decryptCaesar("487", 8) == "487");
    CHECK(decryptCaesar("Dora the explorer!", 0) == "Dora the explorer!");
    CHECK(decryptCaesar("Dop", 26) == "Dop");

    CHECK(decryptCaesar(encryptCaesar("My name is Inigo Montoya. You killed my father. PREPARE TO DIE!!!", 7), 7) == "My name is Inigo Montoya. You killed my father. PREPARE TO DIE!!!");
}

TEST_CASE("decryptVigenere(cipher_text, rshift)") {
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("jevp", "helloworld") == "cake");
    CHECK(decryptVigenere("", "wow") == "");
    CHECK(decryptVigenere("  ", "cool") == "  ");
    CHECK(decryptVigenere("eauI 999 eaui", "cake") == "cakE 999 cake");
    CHECK(decryptVigenere("hi", "") == "hi");
    CHECK(decryptVigenere("z", "z") == "a");
	CHECK(decryptVigenere("z", "Z") == "a");

    CHECK(decryptVigenere(encryptVigenere("My name is Inigo Montoya. You killed my father. PREPARE TO DIE!!!", "lollipop"), "lollipop") == "My name is Inigo Montoya. You killed my father. PREPARE TO DIE!!!");
}

TEST_CASE("decode(cipher_text)") {
    std::string txt = "\'Hello, world!\' How are you today?";
    CHECK(decode(encryptCaesar(txt, 7)) == txt);
    CHECK(decode("\'Olssv, dvysk!\' Ovd hyl fvb avkhf?") == txt);

    txt = "We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.";
    CHECK(decode(encryptCaesar(txt, 14)) == txt);
    
    txt = "In a hole In the GrouNd there lived a hobbit...";
    CHECK(decode(encryptCaesar(txt, -3)) == txt);

    txt = "Is this the real life? Is this just fantasy?";
    CHECK(decode(txt) == txt);

    txt = "12345!?:)(:";
    CHECK(decode("12345!?:)(:") == txt);

    txt = "";
    CHECK(decode("") == txt);

    //Fails because the frequencies don't match the general frequencies of sentences in English; too many 'p's probably.
    // txt = "peter piper picked a pack of pickled peppers pokemon popped popcorn pleasantly";
    // CHECK(decode(encryptCaesar(txt, 15)) == txt);

    //Fails because the frequencies don't match the general frequencies of sentences in English; message is too short
    // txt = "Hello world";
    // CHECK(decode(encryptCaesar(txt, 23)) == txt);
}
