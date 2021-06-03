//Aereo.java
package interfaceAeroporto;

public abstract class Aereo{
	private String fabricante;
	private String modelo;
	private int qtdPassageiros;

	public Aereo(String fabricante, String modelo, int qtdPassageiros){
		this.fabricante = fabricante;
		this.modelo = modelo;
		this.qtdPassageiros = qtdPassageiros;
	}

	public String getFabricante(){
		return fabricante;
	}
	public String getModelo(){
		return modelo;
	}
	public int getQtdPassageiros(){
		return qtdPassageiros;
	}
}