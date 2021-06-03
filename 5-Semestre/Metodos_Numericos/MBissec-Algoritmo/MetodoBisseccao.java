//MetodoBisseccao.java
public class MetodoBisseccao{

	public static double Fx(double x){
		double y = (6*(Math.pow(x,2.0) ))-(Math.acos(x));
		return y;
	}

	public static void main(String args[]){
		int k = 0;

		double a = Double.parseDouble(args[0]);	//Inicio do intervalo pego por parametro
		double b = Double.parseDouble(args[1]);  //Fim do intervalo pego por parametro
		double e = 0.001; //Precissão
		double Xk = (a+b)/2;

		System.out.println("k	|	a	| 	b 	|	Xk	|	F(Xk)");
		while( Math.abs(Fx(Xk)) >= e ){
			Xk = (a+b)/2;
			if(Fx(a)*Fx(Xk)<0){
				b = Xk;
			}else{
				a = Xk;
			}
			System.out.println(k+"	|	"+a+"	|	"+b+"	|	"+Xk+"	|	"+Fx(Xk));
			k++;
		}

	}
}