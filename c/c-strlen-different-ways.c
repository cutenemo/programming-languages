#include <stdio.h>
#include <time.h>

/* Different Ways to Calculate the Length of a String */

/* Source: C Programming: A Modern Approach K.KING */

size_t strlen(const char *s) {
    size_t n;
    for (n = 0; *s != 0; s++) {
        n++;
    }
    return n;
}

size_t strlen_1(const char *s) {
    size_t n = 0;
    for (; *s != 0; s++) {
        n++;
    }
    return n;
}

size_t strlen_2(const char *s) {
    size_t n = 0;
    for (; *s; s++) { /* *s != 0 ~ *s */
        n++;
    }
    return n;
}

size_t strlen_3(const char *s) {
    size_t n = 0;
    for (;*s++;) {
        n++;
    }
    return n;
}

size_t strlen_4(const char *s) {
    size_t n = 0;
    while (*s++) {
        n++;
    }
    return n;
}

size_t strlen_5(const char *s) {
    const char *p = s;
    while (*s++);
    return s - p;
}

int main() {
    clock_t start, end;
    int i = 0;

    char s[1000001];
    while (i < 1000000) {
        s[i++] = 's';
    }
    s[i] = '\0';
    
    start = clock();
    strlen(s);
    end = clock();
    printf("%f\n", (end-start)/(double)CLOCKS_PER_SEC);

    start = clock();
    strlen_1(s);
    end = clock();
    printf("%f\n", (end-start)/(double)CLOCKS_PER_SEC);

    start = clock();
    strlen_2(s);
    end = clock();
    printf("%f\n", (end-start)/(double)CLOCKS_PER_SEC);

    start = clock();
    strlen_3(s);
    end = clock();
    printf("%f\n", (end-start)/(double)CLOCKS_PER_SEC);

    start = clock();
    strlen_4(s);
    end = clock();
    printf("%f\n", (end-start)/(double)CLOCKS_PER_SEC);

    start = clock();
    strlen_5(s);
    end = clock();
    printf("%f\n", (end-start)/(double)CLOCKS_PER_SEC);
    return 0;
}
