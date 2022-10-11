/**********************************************
 * Module: Data Encryption Standard
 *
 * File Name: des_g6.cpp
 *
 * Description: This file includes all the needed algorithms for the DES Encryption/Decryption
 *
 * Author: Group 6
 *
 **********************************************/

#include <iostream>
#include <fstream>
#include <string.h>

/*              GLOBAL          VARIABLES                */
char *plainTextPtr;
char *keyPtr;
char *encryptedTextPtr;
char *plainText;
char *key;
char *encryptedText;
#define MODULE_TEST 1
// FOR TEST ONLY
#if MODULE_TEST

// plainText = "02468aceeca86420";
// key = "0f1571c947d9e859";

// plainTextPtr = plainText;
// keyPtr = key;
#endif
// constats
const uint8_t const_ip[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7};
// data related
/*7osseny:
encryput
read
expansion
xor
*/
/*mo3ta
sbox
decryput
round
initialpermutation
*/
void initialPermutation(char *des_text)
{
}
void expansionETable(char *des_text)
{
}
void XOR(char *input1, char *input2, int bit_size)
{
}
void sbox(char *des_text)
{
}
void permutation_p(char *des_text)
{
}
void round(char *des_text, char *subkey)
{
}
void readPlainText()
{
}
void DES_Encrypt(char *des_text, char *des_key)
{
}

void DES_Decrypt(char *des_encrypted_data, char *des_key)
{
}

int main()
{
}