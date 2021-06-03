public class Mamifero extends Animal{
    private String alimento;

    public Mamifero (String nome,float comprimento,int numPatas,String cor,String ambiente,float velMedia, String alimento){
        super(nome, comprimento, numPatas, cor, ambiente, velMedia);
        this.alimento=alimento;
    }

    public String getAlimento(){
        return alimento;
    }

    public void setAlimento(){
        this.alimento=alimento;
    }

    public void dadosMamifero(){
        System.out.println("Dados do animal:");
        System.out.println(super.getNome());
        System.out.println(super.getComprimento());
        System.out.println(super.getNumPatas());
        System.out.println(super.getCor());
        System.out.println(super.getAmbiente());
        System.out.println(super.getVelMedia());
        System.out.println(getAlimento());
    }
}