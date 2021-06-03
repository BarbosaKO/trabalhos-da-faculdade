//TransporteAereo.java
package interfaceAeroporto;

public interface TransporteAereo{
	public String getOrigem();
	public String getDestino();
	public int getPassageiros();
	
	public void voar(String origem,String destino, int passageiros);
}