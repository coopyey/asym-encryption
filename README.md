# Foundations of Network Security Homework 2
The goal of this homework is to write a C program to implement a simple stream cipher. The program should accept a plaintext file name as user input and an integer seed value. The program should implement a function for encryption and a separate function for decryption.
### Objectives of Functions:
###### Encryption:
Take the seed input value and file name as parameters. It opens the file (giving an error if the file does not exist) and reads one character a a time from that file. For each charact read it generates a new random character and XORs both the characters in order to produce the ciphertext character. Finally, write the entire ciphertext to a new file. The ciphertext should *not* store the intermediate random text string.
###### Decryption:
Take a seed value and the ciphertext file name as parameters and decrypts the given file. It should open the ciphertext file, generate the same sequence of random characters (should the same seed as encryption be used), and XOR it one character at a time with the ciphertext characters to produce the original plaintext.
### Implementation Information:
###### General Information:
The program will put the user into a looping menu where they can choose to encrypt, decrypt, or quit. As stated above this program will intake a filename and a seed value. Based on your choice it will feed your inputs into the encryption or decryption function and commence encrypting or decrypting the input file based upon the seed value you chose. If you encrypt a file with a seed, then decrypt the output file with the same seed, it will produce the original plaintext.
###### Special considerations:
All input and output files go into the textfiles directory. Please place any input files that you wish to use into this directory. The makefile commands are set to not delete any input options unless they are prefixed with "p_" or "c_", so be sure your input files are not prefixed with that if you run the clean or cleanout command. That being said, the program will automatically prefix any file you encrypt with "c_" so the final name will be "c_<input file>.txt" and will do the same for files you decrypt, except with "p_" so outputted plaintext files will be "p_<input file>.txt". Because of this implementation you may run the program as many times as you wish without recompiling.
###### How to run (on Linux):
1. From the main directory run "make all"
2. Run "./prog"
3. Choose your options & run the program
4. ???
5. Profit!

If you wish to delete your output run "make cleanout".
