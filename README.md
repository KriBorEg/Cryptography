Simple cryptography tool

This program lets you encrypt (hide) or decrypt (reveal) text using two simple cryptography methods:
 1. Caesar Cipher – shifts each letter by a number (e.g., A → D if shift is 3).
 2. Vigenère Cipher – uses a word (key) to decide how each letter is shifted.
You can run the program, choose what you want to do, and it will keep looping until you decide to exit.

How it is made:

I have tried to keep everything in one main.c, since I find it easier to navigate with my level of programming skills.

The tools used in the code are as follows:
  #include <stdio.h>  (makes it possible to use: "printf", "fgets" and "scanf")
  #include <stdlib.h> (makes it possible to use: "exit")
  #include <string.h> (makes it possible to use: "strcmp" (stringcompare) and "strlen" (stringlength))
  #include <ctype.h>  (makes it possible to use: "isalpha" and "isupper" (tests for uppercase charachters))

I have divided the code into four sections:
  1. caesar code
       - Where I write the function of the caesar encryption/decryption
  2. vigenere code
       - Where I write the function of the vigenere encryption/decryption
  3. readlines code
       - Where I write the function of helper, which make the code able to read the userinput without the newline \n
  4. main code
       - Where the cryptography tool is run from.
    
