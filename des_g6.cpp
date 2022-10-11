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
vector<uint8_t> plainText;
vector<uint8_t>* plainTextPtr;

vector<uint8_t> key;
vector<uint8_t>* keyPtr;

vector<uint8_t> encryptedText;
vector<uint8_t>* encryptedTextPtr;


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
void initialPermutation(char *des_text)
{
}
void expansionETable(char *des_text){

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
void readFile(string filePath, vector<uint8_t>** ptr, vector<uint8_t>* data){
    // IF THERE WAS A DELIMITER WE WILL BE USING GETLINE TO BUFFER THE STRING OF PLAINTEXT
    //  FOR NOW, THE DELIMITER IS THE SPACE
    FILE* input_file = fopen(filePath.c_str(), "r");
    if (input_file == nullptr) {
        cerr << "Could not open the file - '"
             << filePath.c_str() << "'" << endl;
        return;
    }
    *ptr = data;
    while(!feof(input_file)){
        (*data).push_back(getc(input_file));
    }
    (*data).pop_back();
    fclose(input_file);
}
// THIS IS OUR USER INTERFACE WE CAN CHANGE IT EASILY FROM HERE
void fillParams(void){
    string fileName;
    cout << "Please insert the file path of the plain text: " << endl
         << "If you to decrypt, please type \"0\"" << endl;

    if (fileName != "0")
    {
        cin >> fileName;
        readFile(fileName, &plainTextPtr, &plainText);
    }
    cout << "Please insert the file path of the key: " << endl;
    cin >> fileName;
    readFile(fileName, &keyPtr, &key);
    cout << "Please insert the file path of the encrypted text: " << endl
         << "If you want to encrypt, please type \"0\"" << endl;
    if (fileName != "0")
    {
        cin >> fileName;
        readFile(fileName, &encryptedTextPtr, &encryptedText);
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
