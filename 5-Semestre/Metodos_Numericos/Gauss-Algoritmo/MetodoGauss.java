//MetodoGauss.java
//Feito por:	Gabriel Barbosa da Silva. Curso: Ciência da Computação. IFSP Campus Salto.
// 				Lucas Mattos Santiago. Curso: Ciência da Computação. IFSP Campus Salto.

public class MetodoGauss{
	public static void main(String args[]){
		// CONFIGURE PARA A SUA MATRIZ 
		int n = 4;
		float m = 0;
		float[][] x = new float[4][1];
		float[][] u = {{2,1,0,0},{4,3,3,1},{8,7,9,5},{6,7,9,8}};
		float[][] c = {{99},{69},{2},{9}};
		// ***************************************************

		// ESCALONAMENTO *************************************
		for(int j = 0; j<=n-2; j++){

			for(int i = j+1; i<=n-1; i++){

				m = u[i][j] / u[j][j];
				u[i][j] = 0;

				for(int k = j+1; k<=n-1; k++){
					u[i][k] = u[i][k] - (m * u[j][k]);
				}

				c[i][0] = c[i][0] - (m * c[j][0]);

			}
		}
		// ***************************************************

		for(int j = 0; j<n; j++){
			for(int k = 0; k<n; k++){
				System.out.print(" "+u[j][k]+" ");
			}
			System.out.println();
		}
		System.out.println();
		for(int j = 0; j<n; j++){
			System.out.println(c[j][0]);
		}
		System.out.println();
		//SUBSTITUIÇÃO REGRESSIVA ************************
		
		for(int i = n-1; i>=0; i--){
			x[i][0] = c[i][0];

			for(int j = i+1; j<=n-1; j++){
				x[i][0] =  x[i][0] - (u[i][j] * x[j][0]);
			}
			x[i][0] = x[i][0] / u[i][i];
		}

		//Mostra vetor X
		for(int k = 0; k<n; k++)
			System.out.println("x"+(k+1)+" = "+x[k][0]);

		//*************************************************

	}
}