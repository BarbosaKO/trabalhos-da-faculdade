#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 7;
    int *p = &a;
    int **pp = &p;

    printf("a = %d &a = %d\n", a,&a);
    printf("p = %d *p = %d &p = %d\n", p,*p,&p);
    printf("pp = %d *pp = %d &pp = %d\n", pp,*pp,&pp);
}
