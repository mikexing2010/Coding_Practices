#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int ret_ind = 0;
    int row, string_ind, skip, alt;
    // include the NULL char
    char *ret = (char *)malloc(strlen(s)+1);

    if (numRows == 1) {
        return s;
    }
    // Let's do this row by row from the top
    for (row = numRows; row > 0; row--){
        alt = 0;

        string_ind = abs(row - numRows);
        while (1) {
            if ((string_ind > strlen(s) -1)) {
                break;
            }
            if (alt == 0) {
                skip = row * 2 - 2;
                alt = 1;
            } else {
                skip = (numRows - row + 1) * 2 - 2;
                alt = 0;
            }
                
            if (row == 1 || row == numRows){
                skip = numRows * 2 - 2;
            }
        
            // printf("%d %d %c\n", string_ind, ret_ind, s[string_ind]);
            ret[ret_ind] = s[string_ind];
            string_ind += skip;
            //printf("%d\n", string_ind);
            ret_ind++;
        }
    }
    ret[strlen(s)] = '\0';
    return ret;
}
int main(int argc, char* argv[]) {
if (argc != 3) {
    printf("example of running: roman_to_int ABCDE 3\n");
    return 1;
}       
char * input = argv[1];
int numRow = atoi(argv[2]);

char *output = convert(input, numRow);
printf("input: %s, output: %s\n", input, output);
return 0;
}
