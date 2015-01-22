#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    
    return strcmp(*ia, *ib);
}

int main(int argc, const char * argv[]) {
    
    char *strings[] = {"Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};

    int i;
    
    size_t strings_len = sizeof(strings) / sizeof(char *); // number of elements
    
    qsort(strings, strings_len, sizeof(char *), compare);
    
    for (i = 0; i < 6; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}