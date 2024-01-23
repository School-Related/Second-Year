
# Basic info: 
the logic is to divide the given data into two equal parts. The left par tand the right part. You then need to perform different operations on both those parths, and swap them. 
It is an educational rather than a secure encryption algorithm. This is a sort of Simlified DES. 
It has similar properties and structure to DES with much smaller parameters. The functionality is still there tho. This is just a simplified version. 

we are going to use an 8 bit plaintext. That is an 8 bit block. it then has a 10 bit key as input and produces an 8 bit block of ciphertxt as the output. 

the S-DES decryption algorithm takes an 8 bit bock of ciphertext and the same 1- bit key used to produce the ciphertext as input and produces the original 8 bit of plaintext as output. 

DES encryption algorithm involves 5 functions: 
1. Initial Permutation (IP)
2. A complex function called F_k which involves both permutation and substitution operations and depends on a key input. 
3. A simple permutation function that switches the two halves of data. 
4. The funciton F_k again. 
A permutation function that is the inverse of the inverse permutation. 

as the key is of length 10, you gotta compress it to 8 bits. 2 keys of such 8 bit lengths. So for keys you have to do a lot of things. 
