OBJECTS = funcs.o caesar.o vigenere.o decryption.o decode.o

main: main.o ${OBJECTS}
	g++ -o main main.o ${OBJECTS}

tests: tests.o ${OBJECTS}
	g++ -o tests tests.o ${OBJECTS}

funcs.o: funcs.cpp funcs.h

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h caesar.h

decryption.o: decryption.cpp decryption.h caesar.h vigenere.h

decode.o: decode.cpp decode.h decryption.h

main.o: main.cpp funcs.h caesar.h vigenere.h decryption.h decode.h

tests.o: tests.cpp  doctest.h caesar.h vigenere.h decryption.h decode.h

clean:
	rm -f main.o tests.o ${OBJECTS}

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

