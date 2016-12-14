#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Example input: 23
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
 *
 * Example input: 3
 * Output: ["d", "e", "f"]
 */

int ret_backtrack_index = 0;
const char*table[8] =  {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
/**
 * Return an array of size *returnSize. The array is an array of strings.
 * Note: The returned array must be malloced, assume caller calls free().
 * Assumption: The input digits will never contain 0 or 1
 */
char** letterCombinations(char* digits, int* returnSize) {
    int numDigits = strlen(digits);
    // letters corresponding to digits 2 to 9

    if (numDigits == 0) {
        *returnSize = 0;
        return 0;
    }     
    // calculate the number of combinations that we are going to have.
    // This is going to be the returnSize
    int num_combinations = 1;
    int i;
    for (i = 0; i < strlen(digits) ; i++) {
        // '2' needs to be indexed at 0
        int table_index = digits[i] - '0' - 2;
        if (table_index < 0) {
            printf("Invalid input: %c\n", digits[i]);
            return 0;
        }
        int len = strlen(table[table_index]);
        num_combinations *= len;       
    }
    *returnSize = num_combinations;
    // This creates an array of pointers that are pointed to char/firstletterofstring
    char **ret = (char **)malloc(num_combinations*sizeof(char *));
    backtracking("", 0, numDigits, ret, digits);
    return ret;
}

//
backtracking (char *partialLetters, int digit, int numdigits, char **ret, char *digits) {
    // base condition
    int i, j;
    if (digit == numdigits-1) {
        // We are on the last letter, so add each last letter as a combination
        // into ret

        for (i = 0; i < strlen(table[digit]); i++) {
            char *newCombo = (char *)malloc(numdigits + 1); // extra space for NULL
            strcpy(newCombo, partialLetters);
            int table_index = digits[digit] - '0' - 2;
            newCombo[numdigits-1] = table[table_index][i];
            newCombo[numdigits] = '\0'; // NULL terminate
            // printf("combo: %s\n", newCombo);
            ret[ret_backtrack_index] = newCombo;
            ret_backtrack_index++;
        }
        return;
    }
    
    for (i = 0; i < strlen(table[digit]); i++) {
        char *newPartial = (char *)malloc(strlen(partialLetters) + 2); // one for NULL, one for new char
        strcpy(newPartial, partialLetters);
        int table_index = digits[digit] - '0' - 2;
        newPartial[strlen(partialLetters)] = table[table_index][i];
        newPartial[strlen(partialLetters)+1] = '\0';
        // printf("partial: %d %s\n", table_index , newPartial);
        backtracking(newPartial, digit+1, numdigits, ret, digits); // Go to the next letter
        // free(newPartial); // Once we have explored this subtree, we can safely 
   }
}

int main(int argc, char *argv[]) {
    int i;
    if (argc != 2) {
        printf("example of running: letterCombination 12\n");
        return 1;
    }
    char *input = argv[1];
    printf("%s\n", input);
    int *returnSize;
    char** output = letterCombinations(input, returnSize);
    printf("returnSize: %d\n", *returnSize);
    for (i = 0; i < *returnSize; i++) {
        printf("%s ", output[i]);
        // free(output[i]);
    }
    return 0;
}
