//MetodoNewtonRaphson.java
public class MetodoNewtonRaphson{

	public static double Fx(double x){
		double y = (6*(Math.pow(x,2.0) ))-(Math.acos(x));
		return y;
	}

	public static double FxDerivada(double x){
		double y = (12*x)-( 1/( Math.sqrt( 1-Math.pow(x,2) ) ) );
		return y;
	}

	public static void main(String args[]){
		int k = 0;

		double a = Double.parseDouble(args[0]);	//Inicio do intervalo pego por parametro
		double b = Double.parseDouble(args[1]);  //Fim do intervalo pego por parametro
		double e = 0.001; //Precissão
		double Xk = a;

		System.out.println("k	|		Xk		|	F(Xk)	|	F'(Xk)");
		Xk = Xk - (Fx(Xk)/FxDerivada(Xk));
		System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk)+"	|	"+FxDerivada(Xk) );
		k++;

		while( Math.abs(Fx(Xk)) > e ){
			Xk = Xk - (Fx(Xk)/FxDerivada(Xk));
			System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk)+"	|	"+FxDerivada(Xk) );
			k++;
		}

	}
}