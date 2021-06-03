//Animal.java
public class Animal{
	private String nome;
	private float comprimento;
	private int numPatas;
	private String cor;
	private String ambiente;
	private float velMedia;

	public Animal(String nome,float comprimento,int numPatas,String cor,String ambiente,float velMedia){
		this.nome = nome;
		this.comprimento = comprimento;
		this.numPatas = numPatas;
		this.cor = cor;
		this.ambiente = ambiente;
		this.velMedia = velMedia;
	}

	//GET
	public String getNome(){
		return nome;
	}

	public float getComprimento(){
		return comprimento;
	}

	public int getNumPatas(){
		return numPatas;
	}

	public String getCor(){
		return cor;
	}

	public String getAmbiente(){
		return ambiente;
	}

	public float getVelMedia(){
		return velMedia;
	}

	//SET
	public void setNome(String nome){
		this.nome = nome;
	}

	public void setComprimento(float comprimento){
		this.comprimento = comprimento;
	}

	public void setNumPatas(int numPatas){
		this.numPatas = numPatas;
	}

	public void setCor(String cor){
		this.cor = cor;
	}

	public void setAmbiente(String ambiente){
		this.ambiente = ambiente;
	}

	public void setVelMedia(float velMedia){
		this.velMedia = velMedia;
	}

	public void geraRelatorio(){
		System.out.println("	Dados do animal:");
		System.out.println(getNome());
		System.out.println(getComprimento());
		System.out.println(getNumPatas());
		System.out.println(getCor());
		System.out.println(getAmbiente());
		System.out.println(getVelMedia());
	}

}