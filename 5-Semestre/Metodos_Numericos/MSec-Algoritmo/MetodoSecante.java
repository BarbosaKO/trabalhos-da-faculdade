//MetodoSecante.java
public class MetodoSecante{

	public static double Fx(double x){
		double y = (6*(Math.pow(x,2.0) ))-(Math.acos(x));
		return y;
	}

	public static void main(String args[]){
		int k = 0;

		double a = Double.parseDouble(args[0]);	//Inicio do intervalo pego por parametro
		double b = Double.parseDouble(args[1]);  //Fim do intervalo pego por parametro
		double e = 0.001; //Precissão
		double Xk,AuxA,AuxB;

		System.out.println("k	|		Xk		|	F(Xk)");
		Xk = a;
		AuxA = a;
		System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk) );
		k++;

		Xk = b;
		AuxB = b;
		System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk) );
		k++;

		while( Math.abs(Fx(Xk)) > e ){
				Xk = ( ( AuxA*Fx(AuxB) )-( AuxB*Fx(AuxA) ) )/ ( Fx(AuxB)-Fx(AuxA) );
				AuxA = AuxB;
				AuxB = Xk;
			System.out.println(k+"	|	"+Xk+"	|	"+Fx(Xk) );
			k++;
		}

	}
}