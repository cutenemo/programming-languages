//
//  Read numbers from a file and store them in an array
//  for xcode, right click the the ".out" file under "Products" and click show in finder
//  this is where you need to store the file
//
//  Created by Fatima Broom on 2/3/15.
//  Copyright (c) 2015 nemo. All rights reserved.
//

#include <stdio.h>

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[10000];

    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        return 0;
    }
    int n = 0;
    while(fscanf(fp, "%d", &a[n++]) > 0) {
        ;
    }
    fclose(fp);

    printf("number of integers = %d\n", n);
    print(a, n);
    return 0;
}
