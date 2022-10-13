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
uint64_t final_generated_key[16] = {0};

uint16_t plainText;
uint16_t plainTextPtr;

uint16_t key;
uint16_t keyPtr;

uint16_t encryptedText;
uint16_t encryptedTextPtr;

typedef unsigned char         uint8;          /*           0 .. 255              */
typedef unsigned long         uint32;         /*           0 .. 4294967295       */
typedef unsigned long long    uint64;         /*       0 .. 18446744073709551615  */

#define BLOCK_SIZE 64U

/*      masks      */
#define checkBit(data, x) ((data >> x) & (1))

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
expansion DONE
xor DONE
*/
/*mo3ta
sbox                (done)
decryput
round               (done)
initialpermutation  (done)
inverse             (done)
*/
uint64_t initialPermutation(uint64_t block)
{
    const uint8_t table[BLOCK_SIZE] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7};
    uint64_t result = 0;
    for (int i = BLOCK_SIZE - 1; i >= 0; i--)
    {
        result = (result << 1) | (checkBit(block, table[i] - 1));
    }
    return result;
}
uint64_t expansionETable(uint64_t block){
    uint64_t result = 0;
    uint32_t count = 0;
    const uint8_t table[] =
    {
        32, 1, 2, 3, 4, 5,
        4 , 5, 6, 7, 8, 9,
        8 , 9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32, 1};
    for(int i = 0; i <= 48; i++){
        result |= (checkBit(block, table[count] - 1) << i);
        count++;
    }
    return result;
}
uint64_t XOR(uint64_t input1, uint64_t input2){
    return (input1 ^ input2);

}
uint64_t sbox(uint64_t block_48)
{
    const uint8_t s_box[][4][16] = {
        {
            {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
            {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
            {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
            {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
        },
        {
            {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
            {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
            {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
            {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
        },
        {
            {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
            {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
            {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
            {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
        },
        {
            {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
            {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
            {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
            {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
        },
        {
            {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
            {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
            {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
            {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
        },
        {
            {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
            {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
            {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
            {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
        },
        {
            {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
            {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
            {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
            {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
        },
        {
            {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
            {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
            {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
            {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11},
        },
    };
    uint64_t result32 = 0;
    uint8_t shift = 0;
    uint8_t working_on_6;
    uint8_t row;
    uint8_t col;
    for (int box = 7; box >= 0; box--)
    {
        working_on_6 = block_48 & 0x3F;
        row = ((working_on_6 >> 4) & 0x2) | ((working_on_6)&0x1);
        col = (working_on_6 >> 1) & 0xF;
        block_48 = block_48 >> 6;
        result32 |= s_box[box][row][col] << shift;
        shift += 4;
        // cout << "working:" << (int)working_on_6 << "   row:" << (int)row << "  col:" << (int)col << "   result32:" << (int)result32 << "   shift:" << (int)shift << endl;
    }
    return result32;
}
uint64_t inverse_permutation(uint64_t block)
{
    const uint8_t table[] =
        {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25};
    uint64_t result = 0;
    for (int i = BLOCK_SIZE - 1; i >= 0; i--)
    {
        result = (result << 1) | (checkBit(block, table[i] - 1));
    }
    return result;
}
uint64_t permutation_p(uint64_t block)
{
}
uint64_t round(uint64_t block, uint64_t subkey)
{
    uint64_t l = block >> 32;
    uint64_t r = block & 0xFFFFFFFF;
    uint64_t work;
    work = expansionETable(r);
    work = XOR(work, subkey);
    work = sbox(work);
    work = permutation_p(work);
    l = XOR(work, l);
    return (r << 32) | (l & 0xFFFFFFFF);
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



uint64_t hex_to_deximal_64(string hexText){
    uint64_t result = 0;
    for(int i = 0; i < hexText.size(); i++){
        result |= ASCIIHexToInt[hexText[i]];
        if(i != hexText.size() - 1)
            result = result << 4;
    }
    return result;
}


/*
 * Description :
 * shift left the key value with specific number of shifts
 */
inline uint32 left_circular_shift_28_bits(uint32 effective_28_bit_key, uint8 no_of_shifts)
{
    return ((effective_28_bit_key << no_of_shifts) | (effective_28_bit_key >> (28 - no_of_shifts))) & 0x0fffffff;
}

/*
 * Description :
 * arrange bits according to permutaion table and resize it.
 */

uint64 permutation(uint64 binary_input, uint64 permutation[], uint8 original_size, uint8 needed_size)
{
    uint64 permutated_binary = 0;
    for (int i = 0; i < needed_size; i++)
    {
        permutated_binary |= (binary_input >> (original_size - permutation[i]) & 1) << needed_size - (i + 1);
    }
    return permutated_binary;
}

/*
 * Description :
 * generate 56 bit key after permutation for first time.
 */
uint64 permuted_choice_1(uint64 general_64_bit_key)
{
    uint64 choice_1_permutation[56] = {57, 49, 41, 33, 25, 17, 9,
                                    1, 58, 50, 42, 34, 26, 18,
                                    10, 2, 59, 51, 43, 35, 27,
                                    19, 11, 3, 60, 52, 44, 36,
                                    63, 55, 47, 39, 31, 23, 15,
                                    7, 62, 54, 46, 38, 30, 22,
                                    14, 6, 61, 53, 45, 37, 29,
                                    21, 13, 5, 28, 20, 12, 4};

    return permutation(general_64_bit_key, choice_1_permutation, 64, 56);
}

/*
 * Description :
 * Generate 48 bit key after permutation for second time.
 */
uint64 permuted_choice_2(uint64 general_64_bit_key)
{
    uint64 choice_2_permutation[48] = {14, 17, 11, 24, 1, 5,
                                    3, 28, 15, 6, 21, 10,
                                    23, 19, 12, 4, 26, 8,
                                    16, 7, 27, 20, 13, 2,
                                    41, 52, 31, 37, 47, 55,
                                    30, 40, 51, 45, 33, 48,
                                    44, 49, 39, 56, 34, 53,
                                    46, 42, 50, 36, 29, 32};

    return permutation(general_64_bit_key, choice_2_permutation, 56, 48);
}

/*
* Description :
* generate key for all 16 round according to des standard.
*/
void generate_key(string key, uint64 *final_generated_key)
{
   int shift_values[16] = {1, 1, 2, 2,
                          2, 2, 2, 2,
                          1, 2, 2, 2,
                          2, 2, 2, 1};
   uint64 general_64_bit_key =hex_to_deximal_64(key);
   uint64 effective_56_bit_key = permuted_choice_1(general_64_bit_key);
   uint64 effective_key_28_bit_left = (effective_56_bit_key >> 28) & 0x0FFFFFFF;
   uint64 effective_key_28_bit_right = effective_56_bit_key & 0x0FFFFFFF;
   for (int i = 0; i < 16; i++)
   {
       effective_key_28_bit_left = left_circular_shift_28_bits(effective_key_28_bit_left, shift_values[i]);
       effective_key_28_bit_right = left_circular_shift_28_bits(effective_key_28_bit_right, shift_values[i]);
       uint64 effective_48_bit_key = permuted_choice_2((effective_key_28_bit_left << 28) | effective_key_28_bit_right);
       final_generated_key[i] = effective_48_bit_key;
   }
}
uint64_t DES_Encrypt_Block(uint64_t des_text, uint64_t* final_generated_key)
{
    int x = 0;
    uint64_t resEncBlock = des_text;
    while(x < 16){
        resEncBlock = round(resEncBlock, final_generated_key[x]);
        cout << "Round " << x << " " << std::hex << resEncBlock << endl; 
        x++;
    }
    x = 0;
    return resEncBlock;
}
void DES_Encrypt(string des_key, string filePath)
{
    FILE *input_file = fopen(filePath.c_str(), "r");
    int x = 0;
    uint64_t currBlock = 0;
    char currChar;
    uint64_t currEncBlock = 0;
    generate_key(des_key, final_generated_key);
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
        currEncBlock = DES_Encrypt_Block(currBlock, final_generated_key);
        cout << "Final Encrypted Text " << currEncBlock << endl;
        x = 0;
        currBlock = 0;
    }
}

void DES_Decrypt(vector<uint8_t> *des_encrypted_data, vector<uint8_t> des_key){

}
int main()
{
    // DES_Encrypt(324234234234, "input.hex");
    // cout << initialPermutation(0x123456789ABCDEF) << endl;
    // cout << std::hex << sbox(0x6117BA866527) << endl;
    // cout << std::hex << inverse_permutation(0xA4CD99543423234);
    // uint64_t x = 0b01111111111111111111111111111111;
    // cout << x << endl;
    // cout << expansionETable(x) << endl;
    // cout << std::hex << round(0xCC00CCFFF0AAF0AA, 0x1B02EFFC7072);
    DES_Encrypt("0f1571c947d9e859", "input.hex");
}
