# Foundations of Network Security Homework 2

The goal of this homework is to write a C program to implement a simple stream cipher. The program should accept a plaintext file name as user input and an integer seed value. The program should implement a function for encryption and a separate function for decryption.
### Functions:
###### Encryption:
Take the seed input value and file name as parameters. It opens the file (giving an error if the file does not exist) and reads one character a a time from that file. For each charact read it generates a new random character and XORs both the characters in order to produce the ciphertext character. FInally, write the entire ciphertext to a new file. The ciphertext should *not* store the intermediate random text string.
###### Decryption:
Take a seed value and the ciphertext file name as parameters and decrypts the given file. It should open the ciphertext file, generate the same sequence of random characters (should the same seed as encryption be used), and XOR it one character at a time with the ciphertext characters to produce the original plaintext.
