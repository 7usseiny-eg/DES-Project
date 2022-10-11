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
void readFile(std::string filePath, std::string* fileData){
    //IF THERE WAS A DELIMITER WE WILL BE USING GETLINE TO BUFFER THE STRING OF PLAINTEXT
    // FOR NOW, THE DELIMITER IS THE SPACE
    newfile.open(filePath.c_str());
    newfile >> *fileData;
}

void DES_Encrypt(char* des_text, char* des_key){

}

void DES_Decrypt(char* des_encrypted_data, char* des_key){

}

int main(){
    std::string fileName;
    std::cout << "Please insert the file path of the plain text: " << std::endl << \
    "If you to decrypt, please type 0" << std::endl;
    if(fileName != "0"){
        std::cin >> fileName;
        readFile(fileName, &plainText);
    }
    std::cout << "Please insert the file path of the key: " << std::endl;
    std::cin >> fileName;
    readFile(fileName, &key);
    std::cout << "Please insert the file path of the encrypted text: " << std::endl << \
    "If you want to encrypt, please type 0" << std::endl;
    if(fileName != "0"){
        std::cin >> fileName;
        readFile(fileName, &encryptedText);
    }
    std::cout << plainText << std::endl;

}