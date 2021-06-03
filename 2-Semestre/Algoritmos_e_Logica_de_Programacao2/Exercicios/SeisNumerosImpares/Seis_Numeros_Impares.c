#include <stdio.h>

int main(){
	int x;
	int i;
	scanf("%d", &x);
	for(i=1;i<=6;){
		if(x%2!=0){
			printf("%d\n", x);
			i++;
		}
		x++;
	}
	return 0;
}