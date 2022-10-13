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
#include <vector>

using namespace std;
/*              GLOBAL          VARIABLES                */
uint16_t plainText;
uint16_t plainTextPtr;

uint16_t key;
uint16_t keyPtr;

uint16_t encryptedText;
uint16_t encryptedTextPtr;

/*      masks      */
#define UPPER32(x) x >> 32
#define LOWER32(x) x && (0x0000FFFF)

#define MODULE_TEST 1
// FOR TEST ONLY
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

int ASCIIHexToInt[] =
    {
        // ASCII
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,

        // 0x80-FF (Omit this if you don't need to check for non-ASCII)
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
// data related
/*7osseny:
encryput
read DONE
expansion ON IT
xor
*/
/*mo3ta
sbox
decryput
round
initialpermutation
*/
uint64_t initialPermutation(uint64_t des_text)
{
}
uint64_t expansionETable(uint64_t des_text)
{
}
uint64_t XOR(uint64_t input1, uint64_t input2, int bit_size)
{
    uint64_t result;
    for (int i = 0; i < bit_size; i++)
    {
    }
}
uint64_t sbox(uint64_t des_text)
{
}
uint64_t permutation_p(uint64_t des_text)
{
}
uint64_t round(uint64_t des_text, uint64_t subkey)
{
}
// uint64_t read64FromFile(string filePath, unsigned int shift){
//     // IF THERE WAS A DELIMITER WE WILL BE USING GETLINE TO BUFFER THE STRING OF PLAINTEXT
//     //  FOR NOW, THE DELIMITER IS THE SPACE
//     FILE* input_file = fopen(filePath.c_str(), "r");
//     uint64_t result = 0;
//     uint64_t tempData = 0;
//     if (input_file == nullptr) {
//         cerr << "Could not open the file - '"
//              << filePath.c_str() << "'" << endl;
//         return -1;
//     }
//     int x = 0;
//     while(!feof(input_file)){
//         while(x != (shift*16)){
//             x++;
//             getc(input_file);
//         }
//         x = 0;
//         while(x < 15){
//             result += ASCIIHexToInt[getc(input_file)];
//             result = result << 4;
//             x++;
//         }
//         return result;
//     }
//     fclose(input_file);
// }
// THIS IS OUR USER INTERFACE WE CAN CHANGE IT EASILY FROM HERE
// void fillParams(void){
//     string fileName;
//     cout << "Please insert the file path of the plain text: " << endl
//          << "If you to decrypt, please type \"0\"" << endl;

//     if (fileName != "0")
//     {
//         cin >> fileName;
//         read64FromFile(fileName, &plainTextPtr, &plainText);
//     }
//     for(int i = 0; i < plainText.size(); i++){
//         cout << plainText[i];
//     }
//     cout << "Please insert the file path of the key: " << endl;
//     cin >> fileName;
//     read64FromFile(fileName, &keyPtr, &key);
//     cout << "Please insert the file path of the encrypted text: " << endl
//          << "If you want to encrypt, please type \"0\"" << endl;
//     if (fileName != "0")
//     {
//         cin >> fileName;
//         read64FromFile(fileName, &encryptedTextPtr, &encryptedText);
//     }
// }
uint64_t DES_Encrypt_Block(uint64_t des_text, uint64_t des_key)
{
    uint64_t result = 0;
    return result;
}
void DES_Encrypt(uint64_t des_key, string filePath)
{
    FILE *input_file = fopen(filePath.c_str(), "r");
    int x = 0;
    uint64_t currBlock = 0;
    char currChar;
    uint64_t currEncBlock = 0;
    while (!feof(input_file))
    {
        while (x < 16)
        {
            currChar = getc(input_file);
            if (currChar == -1)
            {
                fclose(input_file);
                return;
            }
            currBlock |= ASCIIHexToInt[currChar];
            if (x != 15)
                currBlock = currBlock << 4;
            x++;
        }
    }
}

void DES_Decrypt(vector<uint8_t> *des_encrypted_data, vector<uint8_t> des_key)
{
}
int main()
{
    DES_Encrypt(324234234234, "input.hex");
}
