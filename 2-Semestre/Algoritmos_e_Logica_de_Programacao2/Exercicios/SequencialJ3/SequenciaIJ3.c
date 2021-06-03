#include <stdio.h>

int main(){
	int i,j,k,l;

	for(i=1,j=7,l=1,k=1; k<=15;--j,++l,++k){
		printf("I=%d J=%d\n", i,j);
		if(l==3){
			i+=2;
			j+=5;
			l=0;
		}
	}
	return 0;
}