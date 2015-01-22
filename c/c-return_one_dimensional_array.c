#include <stdio.h>
#include <stdlib.h>

#define N 5

/* Returning An Array in C */
/* Ref: http://www.eskimo.com/~scs/cclass/int/sx5.html */

/* (1) This will return a pointer to the array a which only exists in this function */int* bad_function() {
        int a[N];    /* do stuff */
    for (int i=0; i<5; i++)
        a[i] = i;
        return a; /* complains address of stack memory associated with local variable a returned!! */}

/* (2) Instead we could use a static array but every time you call the function, you’re accessing the same array! */
int* using_static() {	static int s[N];    
    /* do stuff */
    for (int i=0; i<N; i++)
        s[i] = i;
    	return s;}

/* (3) we could also declare it as a global variable */int g[N];void using_global() {    for (int i=0; i<N; i++)
        g[i] = i;}
/* (4) send the array itself! */
void send_array(int a[], int n) {
    for (int i=0; i<n; i++)
        a[i] = i*i;
}

void send_array1(int *a, int n) { /* *a and a[] are identical */
    for (int i=0; i<n; i++)
        a[i] = i*i;
}

int* send_array2(int a[], int n) {
    for (int i=0; i<n; i++)
        a[i] = i*i+4;
    return a; /* not needed but could be used for error handeling */
}

/* allocate inside the function */

int* allocate(int n) {
	int *a = malloc(n);
	if(a == NULL)
		return NULL;
    for (int i=0; i<n; i++)
        a[i] = i*i+3;
	return a;
}

int main() {
    
    int *bad_pointer, *okay_pointer, *allocate_pointer;
    int my_array[N], my_array1[N], my_array2[N];
    
    /* (1) bad */
    bad_pointer = bad_function();
    printf("%d\n", bad_pointer[1]);
    
    /* (2) okay */
    okay_pointer = using_static();
    printf("%d\n", okay_pointer[1]);
    
    /* (3) using global */
    using_global();
    printf("%d\n", g[1]);
    
    /* (4) sending the array itself */
    send_array(my_array, N);
    printf("%d\n", my_array[2]);
    
    send_array1(my_array1, N);
    printf("%d\n", my_array1[4]);
    
    *my_array2 = send_array2(my_array2, N);
    printf("%d\n", my_array2[4]);
    
    /* (5) allocate inside the function, downside: 
     (a) need to check if null is returned
     (b) free the array after we're done */
    allocate_pointer = allocate(N);
    printf("%d\n", allocate_pointer[3]);
    
    return 0;
}
