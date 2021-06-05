#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int kara(int u, int v, int n){
    int m,p,q,r,s,pr,qs,y,uv;
    if(n<=3){
        return u*v;
    }else{
        m =ceil(n/2);

        p = floor(u/(pow(10,m)));
        q = u%(int)pow(10,m);

        r = floor(v/(pow(10,m)));
        s = v%(int)pow(10,m);

        pr = kara(p,r,m);
        qs = kara(q,s,m);
        y = kara((p+q), (r+s), (m+1));
        uv = pr * pow(10,(2*m)) + (y - pr - qs) * pow(10 , m) + qs;
        return uv;
    }
}
int main(){
    int mult;
    mult = kara(1004, 1005, 4);
    printf("%d\n", mult);
    return 0;
}
