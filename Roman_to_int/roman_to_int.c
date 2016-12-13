#include <stdio.h>
#include <string.h>

// All the symbols: 
// I/1  
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000
// Example of 1 to 10: I, II, III, IV, V, VI, VII, VIII, IX, X.
// I placed before V or X indicates one less, so four is IV (one less than five) and nine is IX (one less than ten)
// X placed before L or C indicates ten less, so forty is XL (ten less than fifty) and ninety is XC (ten less than a hundred)
// C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand)[5]
// Symbols are placed from left to right in order of value, starting with the largest. However, in a few specific cases, to avoid four characters being repeated in successor, subtractive notation is used.

#define TABLESIZE 13
int romanToInt(char* s) {
    char * symbols[TABLESIZE] = {"IV", "IX", "XL", "XC", "CD", "CM", "I", "V", "X", "L", "C", "D", "M"};
    int value[TABLESIZE] = {4, 9, 40, 90, 400, 900, 1, 5, 10, 50, 100, 500 };
    int integerVal = 0;
    int i, j;
    // go through the strings
    while (i < strlen(s)) {
        int found = 0;
        // go through the lookup table
        for (j = 0; j < TABLESIZE; j++) {
            if (strncmp(s + i, symbols[j], strlen(symbols[j])) == 0) {
                integerVal += value[j];
                i = i + strlen(symbols[j]);
                found = 1;
                break;
            }
        }
        if (found == 0)
            printf("Did not find symbol after substring %s", s+i);
    }
    return integerVal;
}

int main(int argc, char* argv[]) {
if (argc != 2) {
    printf("example of running: roman_to_int XVI\n");
    return 1;
}       
char * input = argv[1];
printf("%s\n", input);
int i = romanToInt(input);
printf("input: %s, output: %d\n", input, i);
return 0;
}
