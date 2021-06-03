//Aeroporto.java
package interfaceAeroporto;

public class Aeroporto{

	private void aceita(TransporteAereo veiculo){
		veiculo.voar(veiculo.getOrigem(),veiculo.getDestino(),veiculo.getPassageiros());
		System.out.println("\n	Transporte aceito!");
		System.out.println("**************************************\n");
	}

	public void getAceita(TransporteAereo veiculo){
		aceita(veiculo);
	}
}