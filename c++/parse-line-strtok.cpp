//
//  main.cpp
//  uhunt
//
//  parse line by strtok
//

#include <iostream>
#include <string.h>

int main() {
    //freopen("sample.in", "r", stdin);
    char line[1000];
    int x[1000] = {0};
    while(fgets(line, 1000, stdin)) {

        // parse x values
        fgets(line, 1000, stdin);
        char *p = strtok(line, " ");
        int n = 0;
        while (p) {
            sscanf(p, "%d", &x[n++]);
            p = strtok(NULL, " ");
        }
        for (int i = 0; i < n; i++) {
            printf("%d", x[i]);
        }
        printf("\n");
    }
    return 0;
}
