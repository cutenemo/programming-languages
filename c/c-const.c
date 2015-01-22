#include <stdio.h>

void foo (const char *p) { /* const is just to say that the value of p is NOT supposed to be changed */
    char *q=NULL;
    /* *p = 0; */    /* Error: Read Only Variable (CONST) */
    /* q = p; */     /* Warning: You're "attempting" to change the value of p (later?) althu this was supposed to be restricted */
    /* p = q; */     /* OK: I can change where it points too, not the value */
}

int main() {
    char *r=NULL;
    foo(r);
    return 0;
}
