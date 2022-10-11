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
std::ifstream newfile;

std::string plainTextPtr;
std::string plainText;

std::string keyPtr;
std::string key;

std::string encryptedTextPtr;
std::string encryptedText;

#define MODULE_TEST 1
//FOR TEST ONLY
#if MODULE_TEST

// plainText = "02468aceeca86420";
// key = "0f1571c947d9e859";

// plainTextPtr = plainText;
// keyPtr = key;
#endif
// FIRST PARAMETER HAS THE PATH OF THE FILE WHILE THE SECOND HAS THE PLACE WHERE THE DATA WILL BE STORED

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
void readFile(std::string filePath, std::string* fileData){
    //IF THERE WAS A DELIMITER WE WILL BE USING GETLINE TO BUFFER THE STRING OF PLAINTEXT
    // FOR NOW, THE DELIMITER IS THE SPACE
    newfile.open(filePath.c_str());
    newfile >> *fileData;
}
void fillParams(void){
    std::string fileName;
    std::cout << "Please insert the file path of the plain text: " << std::endl << \
    "If you to decrypt, please type \"0\"" << std::endl;
    if(fileName != "0"){
        std::cin >> fileName;
        readFile(fileName, &plainText);
    }
    std::cout << "Please insert the file path of the key: " << std::endl;
    std::cin >> fileName;
    readFile(fileName, &key);
    std::cout << "Please insert the file path of the encrypted text: " << std::endl << \
    "If you want to encrypt, please type \"0\"" << std::endl;
    if(fileName != "0"){
        std::cin >> fileName;
        readFile(fileName, &encryptedText);
    }
}
void DES_Encrypt(char *des_text, char *des_key)
{
}

void DES_Decrypt(char *des_encrypted_data, char *des_key)
{
}

int main()
{
    fillParams();
}
