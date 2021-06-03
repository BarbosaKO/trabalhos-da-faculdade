//SubstituicaoRegressiva.java
public class SubstituicaoRegressiva{
	public static void main(String args[]){
		
		// CONFIGURE PARA A SUA MATRIZ
		int n = 4;
		float[][] u = {{2,2,1,1},{0,-2,3/2,-3/2},{0,0,-21/4,-11/4},{0,0,0,1/7}};
		float[][] x = new float[4][1];
		float[][] c = {{7},{-5/2},{-21/4},{0}};
		// CONFIGURE PARA A SUA MATRIZ

		for(int i = n-1; i>=0; i--){
			x[i][0] = c[i][0];

			for(int j = i+1; j<=n-1; j++){
				x[i][0] =  x[i][0] - (u[i][j] * x[j][0]);
			}
			x[i][0] = x[i][0] / u[i][i];
		}

		//Mostra vetor X
		for(int k = 0; k<n; k++)
			System.out.println(x[k][0]);
		
	}
}