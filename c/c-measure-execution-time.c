#include <stdio.h>
#include <time.h>

/* or from the shell> time ./a.out 
 s234-155:test2 nemo$ time ./a.out
 real	0m2.170s
 user	0m2.166s
 sys	0m0.002s
 */
 
int main() {
    clock_t begin, end;
    double time_spent;
    int i;
    
    begin = clock();
        
    for (i=0; i<1000000000; i++)
        continue;
    
    end = clock();
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("%f", time_spent);
    
    return 0;
}