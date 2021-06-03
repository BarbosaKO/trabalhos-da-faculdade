#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double Fx(double x){
	//f(x) = x^3-2x^2-20x+30
	double y;
	y = (pow(x,3))-( 2*( pow(x,2) ) )- (20*x)+30;
	return y;
}

double absoluto(double a){
	double abs;
	if(a<0){
		abs = a*-1;
	}else{
		abs = a;
	}
	return abs;
}

void main(){
	int i;
	double precisao;
	double a,b,x;

	printf("De o inicio do intervalo:\n");
	scanf(" %lf", &a);
	printf("De o fim do intervalo:\n");
	scanf(" %lf", &b);
	printf("De a precisao:\n");
	scanf(" %lf", &precisao);

	printf("\nk | a | b | x \n");

	x = ( (a* (Fx(b)) ) - (b* (Fx(a)) ) ) /( (Fx(b))-(Fx(a)) );

	for(i=0; absoluto(Fx(x)) >= precisao; i++){
		x = ( (a* (Fx(b)) ) - (b* (Fx(a)) ) ) /( (Fx(b))-(Fx(a)) );
		printf("%d | %lf | %lf | %lf \n", i, a, b, x);
		if( (Fx(a)*Fx(x))<0 ){
			b = x;
		}
		else{
			a = x;
		}
	}

}