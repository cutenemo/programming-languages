#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sorting two dimensional character array (strings) in C using qsort
 Source: http://stackoverflow.com/questions/13050641/sorting-2d-array-of-strings-in-c
*/

int cmp(const void *a, const void *b) {
    return strcmp(a, b);
}

int main() {

    int i;
    char set[6][12] = {"Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    
    qsort(set, 6, 12, cmp);
    
    for (i = 0; i < 6; i++) {
        printf("%s\n", set[i]);
    }
    
    return 0;
}