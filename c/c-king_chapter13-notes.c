#include <stdio.h>

int read_line(char str[], int n) {
    int ch, i=0;
    while ((ch=getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int main() {
    // Chapter 13: Strings (C-Programming Language, A Modern Approach)
    //----------------------------------------------------------------
    // (1) Split a string over 2 lines

    printf("(1) hello \
there\n");

    printf("(1) hello "  
           "there\n");
    //----------------------------------------------------------------
    // (2) A string literal gets stored in a char array of length n + 1 (special character \0)
    // with a pointer of type char * pointing at it. (just like how printf's first argument is of type char *)
    char *p = "abc";
    // (2) (a) You can't modify a string literal using the following
    //*p = "ab"; // crash

    //----------------------------------------------------------------
    // (3) Declaring a string using:
    char s[6] = "hello"; // + 1 for \0

    s[0] = 'x';
    printf("(3) %s\n", s); // (3) (a) if there is no space for \0 -> unstable results
    
    char s1[5] = "hello"; // + 1 for \0
    s1[0] = 'x';
    printf("(3) (a) %s\n", s1); // unpredicted result
    // (4) (a) if there is more space, compiler fills it with \0 characters

    //----------------------------------------------------------------
    // (5) Difference between char t[] and char* t

    // a-Can modify the array version and not the pointer version (string literal)
    // b-Can make the pointer version point to ther stuff and not the array
    // c-If both needed do char *p and char t[N] and then p = t;

    //----------------------------------------------------------------
    // (6) printf with %.7s prints 7 chars from s!!
    printf("(6) %.3s", s);

    //----------------------------------------------------------------
    // (7) printing using puts and reading with scanf and gets

    //a- scanf stops at white space and gets at new line (replaced with \0 in the array).
    //b- use %ns with scanf to specify the number with chars
    //c- scanf and gets are unsafe using your own example read_line defined above

    //----------------------------------------------------------------
    // (8) looping thru a string until string[i]='\0' instead of having to check for length
    
    //----------------------------------------------------------------
    // (9) C string library: strcpy, strncpy, strlen, strcat, strncat, strcmp
    // strcmp:
    
    // if the chars match between s1 and s2 and s1[i+1] < s2[i+1] (ascii) then s1 < s2
    // if the chars match between s1 and s2 and s1 has fewer chars then s1 < s2

    //----------------------------------------------------------------
    // (10) while (*p++ = *s++) terminates because all chars except for the null char test true

    //----------------------------------------------------------------
    // (11) planets[][8] = {"earth",....} rows is determined from elements and 8 columns vs
    //     *planets[] = {"earth", ....} more efficient 
    
    return 0;
}
