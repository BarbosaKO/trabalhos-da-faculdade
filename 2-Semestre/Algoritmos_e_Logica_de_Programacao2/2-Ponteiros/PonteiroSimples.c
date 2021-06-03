#include <stdio.h>
int main(){
    int x = 5;
    int *p = NULL;
    p = &x;
    printf("x = %d\n", x);
    printf("*p = %d\n", *p);

    *p = 7;
    printf("x = %d\n", x);
    return 0;
}
