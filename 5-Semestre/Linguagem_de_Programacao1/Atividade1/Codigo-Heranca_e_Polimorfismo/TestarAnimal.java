//TestarAnimal.java
public class TestarAnimal{
	public static void main(String args[]){
		Mamifero camelo = new Mamifero("camelo",150,4,"Amarelo","Terra",2,"Arbustos e grama seca");
		Peixe tubarao = new Peixe("tubarão",300,0,"Cinzento","Mar",(float)1.5,"Barbatanas e cauda");
		camelo.dadosMamifero();
		tubarao.dadosPeixe();
	}
}