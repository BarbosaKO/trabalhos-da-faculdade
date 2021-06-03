//MetodoPontoFixo.java
public class MetodoPontoFixo{

	public static double Fx(double x){
		double y = ((1/2)*x) - Math.sin(3*x);
		return y;
	}

	public static double Phix(double x){
		double y = (Math.sin(3*x))*2;
		return y;
	}

	public static void main(String args[]){
		int k = 0;
		double a = Double.parseDouble(args[0]);	//Inicio do intervalo pego por parametro
		double b = Double.parseDouble(args[1]);  //Fim do intervalo pego por parametro
		double e = 0.001; //Precissão

		System.out.println("k	|	Phi(Xk)		|	F(Phi)");

		double Xk = Phix(a);
		System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk));
		k++;
		while( Math.abs(Fx(Xk)) > e ){
			Xk = Phix(Xk);
			System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk));
			k++;
		}

	}
}