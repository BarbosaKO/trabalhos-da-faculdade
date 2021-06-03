public class Peixe extends Animal{
	private String caracteristica;

	public Peixe (String nome, float comprimento, int numPatas, String cor, String ambiente, float velMedia, String caracteristica){
		super(nome, comprimento, numPatas, cor, ambiente, velMedia);
		this.caracteristica=caracteristica;
	}

	public String getCaracteristica(){
		return caracteristica;
	}

	public void setCaracteristica(){
		this.caracteristica=caracteristica;
	}

	public void dadosPeixe(){
		System.out.println("    Dados do animal:");
        System.out.println(super.getNome());
        System.out.println(super.getComprimento());
        System.out.println(super.getNumPatas());
        System.out.println(super.getCor());
        System.out.println(super.getAmbiente());
        System.out.println(super.getVelMedia());
        System.out.println(getCaracteristica());
	}
}