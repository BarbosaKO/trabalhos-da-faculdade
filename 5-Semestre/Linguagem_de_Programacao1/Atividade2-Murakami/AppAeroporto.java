//AppAeroporto.java
import interfaceAeroporto.*;

public class AppAeroporto{
	public static void main(String args[]){
		//Estanciamento das aeronaves
		Dragao dragaoBrancoDeOlhosAzuis = new Dragao("Takahashi","Dragao Branco De Olhos Azuis",62,"Cidade Megaroide","GRU Airport",4);
		Aviao a318 = new Aviao("Airbus","A318",132,"GRU Airport","Aeroporto Lauro Kortz",129);
		Helicoptero h125 = new Helicoptero("Airbus","H125",8,"Aeroporto Lauro Kortz","Ilha do Kaiba",3);

		//Estanciamento dos aeroportos
		Aeroporto cidade_Megaroide = new Aeroporto();
		Aeroporto gru_Airport = new Aeroporto();
		Aeroporto aeroporto_Lauro_Kortz = new Aeroporto();

		//Pedido de voo #1
		System.out.println("	Solicitação de voo!");
		System.out.println("Aeronave: "+dragaoBrancoDeOlhosAzuis.getModelo());
		cidade_Megaroide.getAceita(dragaoBrancoDeOlhosAzuis);

		//Pedido de voo #2
		System.out.println("	Solicitação de voo!");
		System.out.println("Aeronave: "+a318.getModelo());
		gru_Airport.getAceita(a318);

		//Pedido de voo #3
		System.out.println("	Solicitação de voo!");
		System.out.println("Aeronave: "+h125.getModelo());
		aeroporto_Lauro_Kortz.getAceita(h125);
	}
}