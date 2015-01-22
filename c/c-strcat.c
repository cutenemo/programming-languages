#include <stdio.h>
#include <string.h>

/* Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten by the first character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination. */

char *strcat_1(char *s1, const char *s2) {
    char *p = s1;
    
    while (*p) {
        p++;
    }
    while ((*p++ = *s2++));
    *p = '\0';
    return s1;
}

int main() {
    char *s = "Hello World";
    char r[20] = "LA ";
    
    strcat_1(r, s);
    printf("%s\n", r);
    printf("%d", strcmp(r, s));

    return 0;
}

