#include <stdio.h>

int main(){
	int c;

	scanf("%d", &c);

	int x[c];
	for(int i=0;i<c;i++){
		scanf("%d", &x[i]);
	}
	for(int i=0;i<c;i++){
		if(x[i]%2 != 0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}